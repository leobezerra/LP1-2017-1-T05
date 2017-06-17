#ifndef __OBSERVATION_H__
#define __OBSERVATION_H__

typedef unsigned short int ushort;

class Observation {
    private:
        std::vector<double> features;
    public:
        friend std::istream & operator>> (std::istream &, Observation &);
        friend std::ostream & operator<< (std::ostream &, const Observation &);
        ushort size() const { return features.size(); }
        bool operator==(const Observation &) const;
        const double & operator[](int idx) const { return features[idx]; }
};

namespace std {

  template <>
  struct hash<Observation>
  {
    std::size_t operator()(const Observation & obs) const
    {
        using std::hash;
        std::size_t h;
        for (ushort i = 0; i < obs.size(); i++)
            h ^= hash<double>()(obs[i]); 
        return h;
    }
  };

}

#endif
