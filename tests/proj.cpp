#include "proj/proj.hpp"
#include <UnitTest++/UnitTest++.h>

namespace proj
{

  TEST(Create)
  {
  	rope r2{"hello"};
    rope r3{"world"};
    rope r1{r2, r3};
    rope r4;
  }
  TEST(Index)
  {
  	rope r{"hello"};
  	CHECK_EQUAL('h', r.index(0));
  	CHECK_EQUAL('e', r.index(1));
  	CHECK_EQUAL('l', r.index(2));
  	CHECK_EQUAL('l', r.index(3));
  	CHECK_EQUAL('o', r.index(4));
  	CHECK_THROW(r.index(5), std::length_error);

  	rope r2{"world"};
  	CHECK_EQUAL('w', r2[0]);
  	CHECK_EQUAL('o', r2[1]);
  	CHECK_EQUAL('r', r2[2]);
  	CHECK_EQUAL('l', r2[3]);
  	CHECK_EQUAL('d', r2[4]);
  	CHECK_THROW(r2[5], std::length_error);

    // reference check
    r2[0] = 'x';
    CHECK_EQUAL('x',r2[0]);
  }

  TEST(ToString)
  {
    rope r1{"hello"};
    rope r2{"world"};
    CHECK_EQUAL("hello", r1.toString());
    CHECK_EQUAL("world", r2.toString());
    CHECK_EQUAL("helloworld", r1.concat(r2).toString());
    CHECK_EQUAL("worldhello", r2.concat(r1).toString());
  }

  TEST(Concat)
  {
    CHECK(true);
  	rope r0{"hello"};
  	rope r1{" "};
    rope r3{"! How are you?"};
  	rope r = r0.concat(r1).concat("world");
    CHECK_EQUAL(11, r.length());
    r = r.concat(r3);
    CHECK_EQUAL(25, r.length());


  	CHECK_EQUAL('h', r.index(0));
  	CHECK_EQUAL('e', r.index(1));
  	CHECK_EQUAL('l', r.index(2));
  	CHECK_EQUAL('l', r.index(3));
  	CHECK_EQUAL('o', r.index(4));
  	CHECK_EQUAL(' ', r.index(5));
  	CHECK_EQUAL('w', r[6]);
  	CHECK_EQUAL('o', r[7]);
  	CHECK_EQUAL('r', r[8]);
  	CHECK_EQUAL('l', r[9]);
  	CHECK_EQUAL('d', r[10]);
  	CHECK_EQUAL('!', r[11]);
  	CHECK_EQUAL(' ', r[12]);
  	CHECK_EQUAL('H', r[13]);
  	CHECK_EQUAL('o', r[14]);
  	CHECK_EQUAL('w', r[15]);
  	CHECK_EQUAL(' ', r[16]);
  	CHECK_EQUAL('a', r[17]);
  	CHECK_EQUAL('r', r[18]);
  	CHECK_EQUAL('e', r[19]);
  	CHECK_EQUAL(' ', r[20]);
  	CHECK_EQUAL('y', r[21]);
  	CHECK_EQUAL('o', r[22]);
  	CHECK_EQUAL('u', r[23]);
  	CHECK_EQUAL('?', r[24]);

    rope r2;
    rope t{"test"};
    CHECK_EQUAL("test", r2.concat(t).toString());
    CHECK_EQUAL("test2", r2.concat("test2").toString());

  }

  TEST(Split)
  {
    rope r{"hello world"};
    std::vector<rope> rs1 = r.split(5);
    CHECK_EQUAL("hello", rs1[0].toString());
    CHECK_EQUAL('h', rs1[0][0]);
    CHECK_EQUAL('e', rs1[0][1]);
    CHECK_EQUAL('l', rs1[0][2]);
    CHECK_EQUAL('l', rs1[0][3]);
    CHECK_EQUAL('o', rs1[0][4]);

    CHECK_EQUAL(" world", rs1[1].toString());
    CHECK_EQUAL(' ', rs1[1].index(0));
    CHECK_EQUAL('w', rs1[1].index(1));
    CHECK_EQUAL('o', rs1[1].index(2));
    CHECK_EQUAL('r', rs1[1].index(3));
    CHECK_EQUAL('l', rs1[1].index(4));
    CHECK_EQUAL('d', rs1[1].index(5));

    std::vector<rope> rs2 = r.split(10);
    CHECK_EQUAL("hello worl", rs2[0].toString());
    CHECK_EQUAL("d", rs2[1].toString());
    std::vector<rope> rs3 = r.split(0);
    CHECK_EQUAL("", rs3[0].toString());
    CHECK_EQUAL("hello world", rs3[1].toString());

    CHECK_EQUAL("hello world", r.toString());

    std::vector<rope> rs4 = r.split(11);
    CHECK_EQUAL("hello world", rs4[0].toString());
    CHECK_EQUAL("", rs4[1].toString());


    rope r1{"h"};
    std::vector<rope> rs5 = r1.split(0);
    std::vector<rope> rs6 = r1.split(1);
    CHECK_EQUAL("", rs5[0].toString());
    CHECK_EQUAL("h", rs5[1].toString());
    CHECK_EQUAL("", rs6[1].toString());
    CHECK_EQUAL("h", rs6[0].toString());

  }

  TEST(Insert)
  {
  	rope ro{"hello"};
  	rope rt{"world"};

  	CHECK_EQUAL("worldhello", ro.insert(0,rt).toString());
  	CHECK_EQUAL("hworldello", ro.insert(1,rt).toString());
    CHECK_EQUAL("heworldllo", ro.insert(2,rt).toString());
    CHECK_EQUAL("helworldlo", ro.insert(3,rt).toString());

    CHECK_EQUAL('h', ro.insert(3,rt)[0]);
    CHECK_EQUAL('e', ro.insert(3,rt)[1]);
    CHECK_EQUAL('l', ro.insert(3,rt)[2]);
    CHECK_EQUAL('w', ro.insert(3,rt)[3]);
    CHECK_EQUAL('o', ro.insert(3,rt)[4]);
    CHECK_EQUAL('r', ro.insert(3,rt)[5]);
    CHECK_EQUAL('l', ro.insert(3,rt)[6]);
    CHECK_EQUAL('d', ro.insert(3,rt)[7]);
    CHECK_EQUAL('l', ro.insert(3,rt)[8]);
    CHECK_EQUAL('o', ro.insert(3,rt)[9]);

    CHECK_EQUAL("hellworldo", ro.insert(4,rt).toString());
    CHECK_EQUAL("helloworld", ro.insert(5,rt).toString());

    rope r3;
    CHECK_EQUAL("test", r3.insert(0,"test").toString());
    CHECK_EQUAL("test2", r3.insert(0,"test2").toString());
    CHECK_THROW(r3.insert(1,"test"), std::length_error);

    CHECK_EQUAL("", r3.toString());
  }

  TEST(Remove)
  {
  	rope r{"hello world"};
  	
  	CHECK_EQUAL("hello", r.remove(5, 11).toString());
    CHECK_EQUAL("he" , r.remove(2, 11).toString());
    CHECK_EQUAL("hell", r.remove(4, 11).toString());
    CHECK_EQUAL("hello worl", r.remove(10, 11).toString());
    CHECK_THROW(r.remove(11, 12), std::length_error);
    CHECK_THROW(r.remove(2, 12), std::length_error);
    rope r1{"hello"};
    CHECK_EQUAL("he", r1.remove(2, 5).toString());
    CHECK_EQUAL("", r1.remove(0, 5).toString());
    CHECK_THROW(r1.remove(3, 6), std::length_error);

    rope r2{"h"};
    CHECK_EQUAL("", r2.remove(0, 1).toString());
  }

  TEST(Substring)
  {
  	rope r{"hello world"};
  	CHECK_EQUAL("llo w", r.substr(2, 7).toString());
    CHECK_EQUAL("hello world", r.substr(0, 11).toString());
    CHECK_EQUAL("hello worl", r.substr(0, 10).toString());
    CHECK_EQUAL("h", r.substr(0, 1).toString());
    CHECK_THROW(r.substr(0, 0), std::length_error);

    rope r1{"hello"};
    rope r2 = r1.concat("world").concat("how").concat("are").concat("you");
    CHECK_EQUAL("helloworl", r2.substr(0, 9).toString());
    CHECK_EQUAL("helloworld", r2.substr(0, 10).toString());
    CHECK_EQUAL("helloworldh", r2.substr(0, 11).toString());
    CHECK_EQUAL("helloworldho", r2.substr(0, 12).toString());
    CHECK_EQUAL("helloworldhow", r2.substr(0, 13).toString());
  }

  TEST(Replace)
  {
  	rope r{"hello world"};
  	CHECK_EQUAL("heTESTlo world", r.replace(2, 3, "TEST").toString());
    CHECK_EQUAL("heTESTo world", r.replace(2, 4, "TEST").toString());
    CHECK_EQUAL("heTEST world", r.replace(2, 5, "TEST").toString());
    CHECK_EQUAL("heTESTworld", r.replace(2, 6, "TEST").toString());
    CHECK_EQUAL("heTESTorld", r.replace(2, 7, "TEST").toString());
    CHECK_EQUAL("heTESTrld", r.replace(2, 8, "TEST").toString());
    CHECK_EQUAL("heTEST", r.replace(2, 11, "TEST").toString());
    CHECK_THROW(r.replace(2, 12, "TEST"), std::length_error);

    CHECK_THROW(r.replace(0, 12, "TEST"), std::length_error);
    CHECK_EQUAL("TEST", r.replace(0, 11, "TEST").toString());
    CHECK_EQUAL("TESTd", r.replace(0, 10, "TEST").toString());
    CHECK_EQUAL("TESTld", r.replace(0, 9, "TEST").toString());
    CHECK_EQUAL("TESTrld", r.replace(0, 8, "TEST").toString());
    CHECK_EQUAL("TESTorld", r.replace(0, 7, "TEST").toString());
    CHECK_EQUAL("TESTworld", r.replace(0, 6, "TEST").toString());
    CHECK_EQUAL("TEST world", r.replace(0, 5, "TEST").toString());
    CHECK_EQUAL("TESTo world", r.replace(0, 4, "TEST").toString());
    CHECK_EQUAL("TESTlo world", r.replace(0, 3, "TEST").toString());
    CHECK_EQUAL("TESTllo world", r.replace(0, 2, "TEST").toString());
    CHECK_EQUAL("TESTello world", r.replace(0, 1, "TEST").toString());
    CHECK_EQUAL("TESThello world", r.replace(0, 0, "TEST").toString());
  }

  TEST(Length)
  {
    rope r1;
    CHECK_EQUAL(0, r1.length());
    rope r2{"hello"};
    CHECK_EQUAL(5, r2.length());
    rope r3{"world"};
    CHECK_EQUAL(5, r3.length());
    rope r4{"hello world"};
    CHECK_EQUAL(11, r4.length());

    CHECK_EQUAL(10, r3.concat(r2).length());
    CHECK_EQUAL(21, r2.concat(r3).concat(r4).length());
    CHECK_EQUAL(2, r2.split(2)[0].length());
    CHECK_EQUAL(3, r2.split(2)[1].length());
  }

  TEST(Equal){
    rope r1{"hello"};
    rope r2{"hello"};
    rope r3{"world"};
    CHECK_EQUAL(true, r1.equal(r2));
    CHECK_EQUAL(false, r1.equal(r3));
    CHECK_EQUAL(false, r3.equal(r2));
  }
}  // namespace proj

int
main(int, const char* [])
{
    return UnitTest::RunAllTests();
}
