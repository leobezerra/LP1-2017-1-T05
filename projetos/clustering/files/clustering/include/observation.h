#ifndef __OBSERVATION_H__
#define __OBSERVATION_H__

#include <vector>

typedef unsigned short int ushort;
typedef std::pair<double,double> bound;

class Observation {
    private:
        std::vector<double> features;
    public:
        Observation(void) = default;
        Observation(const std::vector<bound> &);
        friend std::istream & operator>> (std::istream &, Observation &);
        friend std::ostream & operator<< (std::ostream &, const Observation &);
        ushort size() const { return features.size(); }
        bool operator==(const Observation &) const;
        bool operator<(const Observation &) const;
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

typedef bool (*obsCmp)(const Observation &, const Observation &);

#endif
