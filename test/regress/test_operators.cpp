
#include "test.hpp"

template <class T1, class T2>
void test_less(const T1& t1, const T2& t2)
{
   if(!(t1 < t2))
   {
      BOOST_REGEX_TEST_ERROR("Failed < comparison", char);
   }
   if(!(t1 <= t2))
   {
      BOOST_REGEX_TEST_ERROR("Failed <= comparison", char);
   }
   if(!(t1 != t2))
   {
      BOOST_REGEX_TEST_ERROR("Failed != comparison", char);
   }
   if(t1 == t2)
   {
      BOOST_REGEX_TEST_ERROR("Failed == comparison", char);
   }
   if(t1 >= t2)
   {
      BOOST_REGEX_TEST_ERROR("Failed >= comparison", char);
   }
   if(t1 > t2)
   {
      BOOST_REGEX_TEST_ERROR("Failed > comparison", char);
   }
}

template <class T1, class T2>
void test_greater(const T1& t1, const T2& t2)
{
   if(t1 < t2)
   {
      BOOST_REGEX_TEST_ERROR("Failed < comparison", char);
   }
   if(t1 <= t2)
   {
      BOOST_REGEX_TEST_ERROR("Failed <= comparison", char);
   }
   if(!(t1 != t2))
   {
      BOOST_REGEX_TEST_ERROR("Failed != comparison", char);
   }
   if(t1 == t2)
   {
      BOOST_REGEX_TEST_ERROR("Failed == comparison", char);
   }
   if(!(t1 >= t2))
   {
      BOOST_REGEX_TEST_ERROR("Failed >= comparison", char);
   }
   if(!(t1 > t2))
   {
      BOOST_REGEX_TEST_ERROR("Failed > comparison", char);
   }
}

template <class T1, class T2>
void test_equal(const T1& t1, const T2& t2)
{
   if(t1 < t2)
   {
      BOOST_REGEX_TEST_ERROR("Failed < comparison", char);
   }
   if(!(t1 <= t2))
   {
      BOOST_REGEX_TEST_ERROR("Failed <= comparison", char);
   }
   if(t1 != t2)
   {
      BOOST_REGEX_TEST_ERROR("Failed != comparison", char);
   }
   if(!(t1 == t2))
   {
      BOOST_REGEX_TEST_ERROR("Failed == comparison", char);
   }
   if(!(t1 >= t2))
   {
      BOOST_REGEX_TEST_ERROR("Failed >= comparison", char);
   }
   if(t1 > t2)
   {
      BOOST_REGEX_TEST_ERROR("Failed > comparison", char);
   }
}

template <class T1, class T2, class T3>
void test_plus(const T1& t1, const T2& t2, const T3& t3)
{
   if(t1 + t2 != t3)
   {
      BOOST_REGEX_TEST_ERROR("Failed addition", char);
   }
   if(t3 != t1 + t2)
   {
      BOOST_REGEX_TEST_ERROR("Failed addition", char);
   }
}

void test_operators()
{
   test_info<char>::set_typename("sub_match operators");

   std::string s1("a");
   std::string s2("b");
   boost::sub_match<std::string::const_iterator> sub1, sub2;
   sub1.first = s1.begin();
   sub1.second = s1.end();
   sub1.matched = true;
   sub2.first = s2.begin();
   sub2.second = s2.end();
   sub2.matched = true;

   test_less(sub1, sub2);
   test_less(sub1, s2.c_str());
   test_less(s1.c_str(), sub2);
   test_less(sub1, *s2.c_str());
   test_less(*s1.c_str(), sub2);
   test_less(sub1, s2);
   //test_less(s1, sub2);
   test_greater(sub2, sub1);
   test_greater(sub2, s1.c_str());
   test_greater(s2.c_str(), sub1);
   test_greater(sub2, *s1.c_str());
   test_greater(*s2.c_str(), sub1);
   test_greater(sub2, s1);
   //test_greater(s2, sub1);
   test_equal(sub1, sub1);
   test_equal(sub1, s1.c_str());
   test_equal(s1.c_str(), sub1);
   test_equal(sub1, *s1.c_str());
   test_equal(*s1.c_str(), sub1);
   test_equal(sub1, s1);
   //test_equal(s1, sub1);
   test_plus(sub2, sub1, "ba");
   test_plus(sub2, s1.c_str(), "ba");
   test_plus(s2.c_str(), sub1, "ba");
   test_plus(sub2, *s1.c_str(), "ba");
   test_plus(*s2.c_str(), sub1, "ba");
   test_plus(sub2, s1, "ba");
   //test_plus(s2, sub1, "ba");
}