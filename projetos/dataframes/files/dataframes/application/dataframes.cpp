#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <memory>
#include <cassert>

typedef unsigned short int ushort;

class ColumnTraits {
	private:
		std::string name, type;
	public:
		ColumnTraits(std::string & name_) : name(name_), type("") {}
		friend std::ostream & operator<< (std::ostream &, const ColumnTraits &);
		void setType(std::string && value) { type = value; }
		const std::string & getName(void) const { return name; }
		const std::string & getType(void) const { return type; }
};

std::ostream & operator<< (std::ostream & out, const ColumnTraits & col) {
	out << col.name;
	return out;
}

class Column {
	public:
		explicit Column (void) = default;
		Column(const Column & other) = delete;
		Column& operator=(const Column&) = delete;
		friend std::ostream & operator<< (std::ostream &, const Column &);
		virtual std::ostream & print(std::ostream &) const = 0;
		virtual std::ostream & print(std::ostream &, ushort) const = 0;
		virtual void push_back(std::string & value) = 0;
		virtual ushort size(void) = 0;
};

std::ostream & operator<< (std::ostream & out, const Column & col) {
	return col.print(out);
}

class StringColumn : public Column {
	private:
		std::vector<std::string> data;
	public:
		StringColumn(std::string & value) { 
			if (value.size() == 2)
				data.push_back("");
			else
				data.push_back(value.substr(1,value.size()-2)); 
		}
		std::ostream & print(std::ostream & out) const {
			for (ushort i = 0; i < data.size(); i++)
				out << "\"" << data[i] << "\"";
			return out;
		}
		std::ostream & print(std::ostream & out, ushort idx) const {
			out << "\"" << data[idx] << "\"";
			return out;
		}
		void push_back(std::string & value) { 
			if (value.size() == 2)
				data.push_back("");
			else
				data.push_back(value.substr(1,value.size()-2)); 
		}
		ushort size(void) { return data.size(); }
};

class NumColumn : public Column {
	private:
		std::vector<float> data;
	public:
		NumColumn(const std::string & value) { 
			data.push_back(std::stof(value)); 
		}
		std::ostream & print(std::ostream & out) const {
			for (ushort i = 0; i < data.size(); i++)
				out << data[i];
			return out;
		}
		std::ostream & print(std::ostream & out, ushort idx) const {
			out << data[idx];
			return out;
		}
		void push_back(std::string & value) { 
			data.push_back(std::stof(value)); 
		}
		ushort size(void) { return data.size(); }
};

int main (int argc, char * argv[]) {
	std::string buffer;
	std::getline(std::cin, buffer);

	std::vector<ColumnTraits> header;
	std::string field;
	std::istringstream header_buffer(buffer);
	while (std::getline(header_buffer,field,';')) header.push_back(ColumnTraits(field));
	ushort ncols = header.size();

	for (ushort i = 0; i < header.size(); i++) {
		std::cout << header[i];
		if (i+1 != header.size()) std::cout << ';';
	}
	std::cout << std::endl;

	std::getline(std::cin, buffer);
	std::istringstream line(buffer);
	std::vector<std::unique_ptr<Column>> cols;
	for (ushort i = 0; std::getline(line,field,';'); i++) {
		bool is_string = field[0] == '\"';
		header[i].setType(is_string ? "string" : "numeric");
		if (is_string) {
			std::string remaining;
			while (field.back() != '\"') {
				std::getline(line,remaining,';');
				field += remaining; 
			}
		}
		std::unique_ptr<Column> col;
		if (is_string)
			col = std::unique_ptr<Column>(new StringColumn(field));
		else
			col = std::unique_ptr<Column>(new NumColumn(field));
		cols.push_back(std::move(col));
	}

	ushort nrows;
	for (nrows = 1; std::getline(std::cin, buffer); nrows++) {
		std::istringstream line(buffer);
		for (ushort i = 0; std::getline(line,field,';'); i++) {
			bool is_string = field[0] == '\"';
			if (is_string) {
				std::string remaining;
				while (field.back() != '\"') {
					std::getline(line,remaining,';');
					field += ";" + remaining; 
				}
			}
			const std::string & field_type = header[i].getType();
			assert((field_type == "string" && is_string) || (field_type == "numeric" && !is_string));
			cols[i]->push_back(field);
		}
	}

	for (ushort i = 0; i < nrows; i++) {
		for (ushort j = 0; j < cols.size(); j++) {
			cols[j]->print(std::cout, i);
			if (j+1 != cols.size()) std::cout << ";";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}