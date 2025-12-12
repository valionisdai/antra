#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "mylib.h"   

#include <vector>
#include <list>


using StudentVec = Studentas<std::vector>;
using StudentList = Studentas<std::list>;

TEST_CASE("Konstruktorius veikia") {
    StudentVec s;
    CHECK(s.getVardas() == "");
    CHECK(s.getPavarde() == "");
    CHECK(s.getEgz() == 0);
    CHECK(s.getRez() == doctest::Approx(0.0f));
    CHECK(s.getMed() == doctest::Approx(0.0f));
}

TEST_CASE("Setteriai ir getteriai veikia") {
    StudentVec s;
    s.setVardas("Jonas");
    s.setPavarde("Jonaitis");
    s.setEgz(9);
    s.setRez(8.5f);
    s.setMed(7.0f);

    CHECK(s.getVardas() == "Jonas");
    CHECK(s.getPavarde() == "Jonaitis");
    CHECK(s.getEgz() == 9);
    CHECK(s.getRez() == doctest::Approx(8.5f));
    CHECK(s.getMed() == doctest::Approx(7.0f));
}

TEST_CASE("Pridedami pažymiai") {
    StudentVec s;
    s.addPazymys(10);
    s.addPazymys(8);
    s.addPazymys(7);

    CHECK(s.getPaz().size() == 3);
}

TEST_CASE("Kopijavimo konstruktorius") {
    StudentVec s1;
    s1.setVardas("A");
    s1.setPavarde("B");
    s1.addPazymys(9);

    StudentVec s2 = s1;

    CHECK(s2.getVardas() == "A");
    CHECK(s2.getPavarde() == "B");
    CHECK(s2.getPaz().size() == 1);
}

TEST_CASE("Move konstruktorius") {
    StudentVec s1;
    s1.setVardas("Move");
    s1.setPavarde("Test");

    StudentVec s2 = std::move(s1);

    CHECK(s2.getVardas() == "Move");
    CHECK(s2.getPavarde() == "Test");
}

TEST_CASE("Isvesties operatorius") {
    StudentVec s;
    s.setVardas("Jonas");
    s.setPavarde("Jonaitis");

    std::ostringstream out;
    out << s;

    CHECK(out.str() == "Jonas Jonaitis ");
}
