#include <string>

#include <boost/python.hpp>
using namespace boost::python;

struct World
{
    void set(const std::string& msg) { this->msg = msg; }
    std::string greet() const { return msg; }
    std::string msg;
};

BOOST_PYTHON_MODULE(hello)
{
    class_<World>("World")
        .def("greet", &World::greet)
        .def("set", &World::set)
    ;
}
