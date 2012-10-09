#include "test.h"

static void test_bool_ord(void) {
  CU_ASSERT(eq(True, True));
  CU_ASSERT(eq(False, False));
  CU_ASSERT(gt(True, False));
  CU_ASSERT(lt(False, True)); 
}

static void test_bool_hash(void) {
  CU_ASSERT(hash(True) is 1);
  CU_ASSERT(hash(False) is 0);
}

static void test_bool_asctypes(void) {
  CU_ASSERT(as_long(True) is 1);
  CU_ASSERT(as_long(False) is 0);
  CU_ASSERT(as_double(True) is 1.0);
  CU_ASSERT(as_double(False) is 0.0);
  CU_ASSERT_STRING_EQUAL(as_str(False), "False");
  CU_ASSERT_STRING_EQUAL(as_str(True), "True");
}

static void test_char_create(void) {
  
  var char0 = $(Char, 'a');
  var char1 = new(Char, 'b');
  var char2 = copy(char0);
  
  CU_ASSERT(char0);
  CU_ASSERT(char1);
  
  CU_ASSERT(as_char(char0) is 'a');
  CU_ASSERT(as_char(char1) is 'b');
  CU_ASSERT(as_char(char2) is 'a');
  
  assign(char1, char2);
  
  CU_ASSERT(char1 != char2);
  CU_ASSERT(as_char(char1) is 'a');
  
  delete(char1);
  delete(char2);
  
}

static void test_char_ord(void) {
  CU_ASSERT( gt($(Char, 'b'), $(Char, 'a')) );
  CU_ASSERT( gt($(Char, 'z'), $(Char, 'g')) );
  CU_ASSERT( gt($(Char, 'a'), $(Char, 'A')) );
  CU_ASSERT( gt($(Char, 'G'), $(Char, 'F')) );
  CU_ASSERT( lt($(Char, 'V'), $(Char, 't')) );
  CU_ASSERT( lt($(Char, 'C'), $(Char, 'x')) );
  CU_ASSERT( lt($(Char, 'Y'), $(Char, 'Z')) );
  CU_ASSERT( eq($(Char, 'h'), $(Char, 'h')) );
  CU_ASSERT( ge($(Char, 'T'), $(Char, 'T')) );
  CU_ASSERT( le($(Char, 'A'), $(Char, 'a')) );
  CU_ASSERT( le($(Char, 'a'), $(Char, 'a')) );
  CU_ASSERT( neq($(Char, 'T'), $(Char, 'V')) );
}

static void test_char_hash(void) {
  CU_ASSERT( hash($(Char, 'A')) is 65);
  CU_ASSERT( hash($(Char, 'b')) is 98);
  CU_ASSERT( hash($(Char, 'z')) is 122);
}

static void test_int_create(void) {
  
  var int0 = $(Int, 1);
  var int1 = new(Int, 24313);
  var int2 = copy(int0);
  
  CU_ASSERT(int0);
  CU_ASSERT(int1);
  CU_ASSERT(int2);
  
  CU_ASSERT(as_long(int0) is 1);
  CU_ASSERT(as_long(int1) is 24313);
  CU_ASSERT(as_long(int2) is 1);
  
  assign(int2, int1);
  
  CU_ASSERT( not(int2 is int1) );
  CU_ASSERT(as_long(int2) is 24313);
  
  delete(int1);
  delete(int2);
  
}

static void test_int_ord(void) {
  
  CU_ASSERT( gt($(Int, 5),    $(Int, 0)) );
  CU_ASSERT( gt($(Int, 5133), $(Int, 232)) );
  CU_ASSERT( lt($(Int, 2332), $(Int, 9992)) );
  CU_ASSERT( lt($(Int, 34),   $(Int, 323)) );
  CU_ASSERT( eq($(Int, 111),  $(Int, 111)) );
  CU_ASSERT( eq($(Int, 23),   $(Int, 23)) );
  CU_ASSERT( ge($(Int, 289),  $(Int, 289)) );
  CU_ASSERT( ge($(Int, 8734), $(Int, 289)) );
  CU_ASSERT( le($(Int, 166),  $(Int, 166)) );
  CU_ASSERT( le($(Int, 11),   $(Int, 888)) );
  CU_ASSERT( neq($(Int, 324), $(Int, 685)) );
  CU_ASSERT( neq($(Int, 34),  $(Int, 54)) );
  
}

static void test_int_hash(void) {
  
  CU_ASSERT( hash($(Int, 34)) is 34 );
  CU_ASSERT( hash($(Int, 11)) is 11 );
  CU_ASSERT( hash($(Int, 06)) is 06 );
  CU_ASSERT( hash($(Int, 8213)) is 8213 );
  
}

static void test_int_num(void) {
  
  var tester = $(Int, 0);
  
  CU_ASSERT(as_long(tester) is 0);
  
  add(tester, $(Int, 10)); CU_ASSERT(as_long(tester) is 10);
  sub(tester, $(Int, 4)); CU_ASSERT(as_long(tester) is 6);
  mul(tester, $(Int, 10)); CU_ASSERT(as_long(tester) is 60);
  divide(tester, $(Int, 3)); CU_ASSERT(as_long(tester) is 20);
  negate(tester); CU_ASSERT(as_long(tester) is -20);
  absolute(tester); CU_ASSERT(as_long(tester) is 20);
  absolute(tester); CU_ASSERT(as_long(tester) is 20);
  
}

static void test_int_parse(void) {
  
  var f = open($(File, NULL), "test.bin", "w");
  
  put(f, Int, $(Int, 10));
  put(f, Int, $(Int, 32));
  
  close(f);
  
  f = open($(File, NULL), "test.bin", "r");
  
  var fst = get(f, Int);
  var snd = get(f, Int);
  
  close(f);
  
  CU_ASSERT(as_long(fst) is 10);
  CU_ASSERT(as_long(snd) is 32);
  
  delete(fst);
  delete(snd);
  
}

static void test_real_create(void) {
  
  var real0 = $(Real, 1.0);
  var real1 = new(Real, 24.313);
  var real2 = copy(real0);
  
  CU_ASSERT(real0);
  CU_ASSERT(real1);
  CU_ASSERT(real2);
  
  CU_ASSERT(as_double(real0) is 1.0);
  CU_ASSERT(as_double(real1) is 24.313);
  CU_ASSERT(as_double(real2) is 1.0);
  
  assign(real2, real1);
  
  CU_ASSERT( not(real2 is real1) );
  CU_ASSERT(as_double(real2) is 24.313);
  
  delete(real1);
  delete(real2);
  
}

static void test_real_ord(void) {
  
  CU_ASSERT( gt($(Real, 5.0),    $(Real, 0.0)) );
  CU_ASSERT( gt($(Real, 51.33), $(Real, 2.32)) );
  CU_ASSERT( lt($(Real, 23.32), $(Real, 99.92)) );
  CU_ASSERT( lt($(Real, 31.0),   $(Real, 32.3)) );
  CU_ASSERT( eq($(Real, 1.11),  $(Real, 1.11)) );
  CU_ASSERT( eq($(Real, 23.55),   $(Real, 23.55)) );
  CU_ASSERT( ge($(Real, 2.89),  $(Real, 2.89)) );
  CU_ASSERT( ge($(Real, 87.34), $(Real, 2.89)) );
  CU_ASSERT( le($(Real, 16.6),  $(Real, 16.6)) );
  CU_ASSERT( le($(Real, 1.1),   $(Real, 88.8)) );
  CU_ASSERT( neq($(Real, 3.24), $(Real, 6.85)) );
  CU_ASSERT( neq($(Real, 3.4),  $(Real, 5.4)) );
  
}

union type_interp {
  double as_double;
  long as_long;
};

static void test_real_hash(void) {
  
  union type_interp r0 = { 34.0 };
  union type_interp r1 = { 11.0 };
  union type_interp r2 = { 0.6 };
  union type_interp r3 = { 82.13 };
  
  CU_ASSERT( hash($(Real, 34.0)) is r0.as_long );
  CU_ASSERT( hash($(Real, 11.0)) is r1.as_long );
  CU_ASSERT( hash($(Real, 0.6)) is r2.as_long );
  CU_ASSERT( hash($(Real, 82.13)) is r3.as_long );
  
}

static void test_real_num(void) {
  
  double base = 0.0;
  var mirror = $(Real, 0.0);
  
  base += 0.1; add(mirror, $(Real, 0.1));
  CU_ASSERT(as_double(mirror) is base);
  
  base *= 4.0; mul(mirror, $(Real, 4.0));
  CU_ASSERT(as_double(mirror) is base);
  
  base /= 2.0; divide(mirror, $(Real, 2.0));
  CU_ASSERT(as_double(mirror) is base);
  
  base = -base; negate(mirror);
  CU_ASSERT(as_double(mirror) is base);  
  
  base = fabs(base); absolute(mirror);
  CU_ASSERT(as_double(mirror) is base);  
  
}

static void test_real_parse(void) {
  
  var f = open($(File, NULL), "test.bin", "w");
  
  put(f, Real, $(Real, 1.0));
  put(f, Real, $(Real, 3.2));
  
  close(f);
  
  f = open($(File, NULL), "test.bin", "r");
  
  var fst = get(f, Real);
  var snd = get(f, Real);
  
  close(f);
  
  CU_ASSERT(as_double(fst) is 1.0);
  CU_ASSERT(as_double(snd) is 3.2);
  
  delete(fst);
  delete(snd);
  
}

static void test_string_create(void) {
  
  var s0 = $(String, "Hello");
  var s1 = new(String, "There");
  var s2 = copy(s0);
  
  CU_ASSERT(s0);
  CU_ASSERT(s1);
  CU_ASSERT(s2);
  
  CU_ASSERT_STRING_EQUAL(as_str(s0), "Hello");
  CU_ASSERT_STRING_EQUAL(as_str(s1), "There");
  CU_ASSERT_STRING_EQUAL(as_str(s2), "Hello");
  
  assign(s2, s1);
  
  CU_ASSERT( not(s1 is s2) );
  CU_ASSERT_STRING_EQUAL( as_str(s2), "There" );
  
  delete(s1);
  delete(s2);
  
}

static void test_string_ord(void) {
  
  CU_ASSERT( gt($(String, "Apple"),    $(String, "Ball")) );
  CU_ASSERT( gt($(String, "cat"), $(String, "dog")) );
  CU_ASSERT( lt($(String, "great"), $(String, "hello")) );
  CU_ASSERT( lt($(String, "Yellow"),   $(String, "Zoo")) );
  CU_ASSERT( eq($(String, "Hello"),  $(String, "Hello")) );
  CU_ASSERT( eq($(String, "there"),   $(String, "there")) );
  CU_ASSERT( ge($(String, "Hello"),  $(String, "Hello")) );
  CU_ASSERT( ge($(String, "tooting"), $(String, "Red")) );
  CU_ASSERT( le($(String, "guard"),  $(String, "guardian")) );
  CU_ASSERT( le($(String, "keep"),   $(String, "keep")) );
  CU_ASSERT( neq($(String, "Hello"), $(String, "hello")) );
  CU_ASSERT( neq($(String, "group"),  $(String, "GROUP")) );
  
}

static void test_string_collection(void) {
  
  var s0 = new(String, "Balloons");
  
  CU_ASSERT(len(s0) is 8);
  CU_ASSERT(contains(s0, $(String, "Ball")));
  CU_ASSERT(contains(s0, $(String, "oon")));
  CU_ASSERT(contains(s0, $(String, "Balloons")));
  CU_ASSERT(contains(s0, $(Char, 'l')));
  
  discard(s0, $(String, "oons"));
  
  CU_ASSERT_STRING_EQUAL(as_str(s0), "Ball");
  
  clear(s0);
  
  CU_ASSERT(len(s0) is 0);
  CU_ASSERT_STRING_EQUAL(as_str(s0), "");
  
  
  delete(s0);
  
}

static void test_string_hash(void) {
  
  // TODO: Add in behaviour for hash testing
  
}

static void test_string_parse(void) {
  
  var f = open($(File, NULL), "test.bin", "w");
  
  put(f, String, $(String, "Hello"));
  put(f, String, $(String, "There"));
  
  close(f);
  
  f = open($(File, NULL), "test.bin", "r");
  
  var fst = get(f, String);
  var snd = get(f, String);
  
  close(f);
  
  CU_ASSERT_STRING_EQUAL(as_str(fst), "Hello");
  CU_ASSERT_STRING_EQUAL(as_str(snd), "There");
  
  delete(fst);
  delete(snd);
  
}

static void test_string_reverse(void) {
  
  var s0 = new(String, "Hello");
  var s1 = new(String, "olleH");
  
  CU_ASSERT( neq(s0, s1) );
  
  reverse(s0);
  
  CU_ASSERT( eq(s0, s1) );
  
  delete(s0);
  delete(s1);
  
}

static void test_array_create(void) {
  
  var a0 = new(Array, Int, 3, $(Int, 1), $(Int, 5), $(Int, 10));
  var a1 = new(Array, Real, 2, $(Real, 1.1), $(Real, 2.2));
  var a2 = copy(a0);
  
  CU_ASSERT(a0);
  CU_ASSERT(a1);
  CU_ASSERT(a2);
  
  CU_ASSERT(a0 != a1);
  CU_ASSERT(a0 != a2);
  CU_ASSERT(a1 != a2);
  
  CU_ASSERT( eq(at(a0, 0), $(Int, 1)) );
  CU_ASSERT( eq(at(a1, 0), $(Real, 1.1)) );
  CU_ASSERT( eq(at(a2, 0), $(Int, 1)) );
  
  assign(a2, a1);
  
  CU_ASSERT(a2 != a1);
  CU_ASSERT( eq(at(a2, 0), $(Real, 1.1)) );
  
  delete(a0);
  delete(a1);
  delete(a2);
  
}

static void test_array_eq(void) {
  
  var a0 = new(Array, Int, 3, $(Int, 1), $(Int, 5), $(Int, 10));
  var a1 = new(Array, Int, 3, $(Int, 1), $(Int, 5), $(Int, 10));
  var a2 = new(Array, Int, 3, $(Int, 2), $(Int, 5), $(Int, 10));
  
  CU_ASSERT(a0 != a1);
  CU_ASSERT(a0 != a2);
  
  CU_ASSERT( eq(a0, a1) );
  CU_ASSERT( neq(a0, a2) );
  
  delete(a0);
  delete(a1);
  delete(a2);
  
}

static void test_array_collection(void) {
  
  var a0 = new(Array, Int, 3, $(Int, 1), $(Int, 5), $(Int, 10));
  
  CU_ASSERT(len(a0) is 3);
  CU_ASSERT(contains(a0, $(Int, 1)));
  CU_ASSERT(contains(a0, $(Int, 5)));
  
  discard(a0, $(Int, 5));
  
  CU_ASSERT(len(a0) is 2);
  CU_ASSERT(contains(a0, $(Int, 1)));
  CU_ASSERT(not contains(a0, $(Int, 5)));
  
  clear(a0);
  
  CU_ASSERT(len(a0) is 0);
  CU_ASSERT(not contains(a0, $(Int, 1)));
  
  delete(a0);
  
}

static void test_array_push(void) {
  
  var a0 = new(Array, Int, 0);
  
  CU_ASSERT(len(a0) is 0);
  
  push(a0, $(Int, 1));
  
  CU_ASSERT(len(a0) is 1);
  CU_ASSERT( eq(at(a0, 0), $(Int, 1)) );
  
  push_back(a0, $(Int, 3));
  
  CU_ASSERT(len(a0) is 2);
  CU_ASSERT( eq(at(a0, 0), $(Int, 1)) );
  CU_ASSERT( eq(at(a0, 1), $(Int, 3)) );
  
  push_front(a0, $(Int, 10));
  
  CU_ASSERT(len(a0) is 3);
  CU_ASSERT( eq(at(a0, 0), $(Int, 10)) );
  CU_ASSERT( eq(at(a0, 1), $(Int, 1)) );
  CU_ASSERT( eq(at(a0, 2), $(Int, 3)) );
  
  push_at(a0, $(Int, 20), 1);
  
  CU_ASSERT(len(a0) is 4);
  CU_ASSERT( eq(at(a0, 0), $(Int, 10)) );
  CU_ASSERT( eq(at(a0, 1), $(Int, 20)) );
  CU_ASSERT( eq(at(a0, 2), $(Int, 1)) );
  CU_ASSERT( eq(at(a0, 3), $(Int, 3)) );
  
  pop_at(a0, 2);
  
  CU_ASSERT(len(a0) is 3);
  CU_ASSERT( eq(at(a0, 0), $(Int, 10)) );
  CU_ASSERT( eq(at(a0, 1), $(Int, 20)) );
  CU_ASSERT( eq(at(a0, 2), $(Int, 3)) );
  
  pop_front(a0);
  
  CU_ASSERT(len(a0) is 2);
  CU_ASSERT( eq(at(a0, 0), $(Int, 20)) );
  CU_ASSERT( eq(at(a0, 1), $(Int, 3)) );
  
  pop_back(a0);
  
  CU_ASSERT(len(a0) is 1);
  CU_ASSERT( eq(at(a0, 0), $(Int, 20)) );
  
  pop(a0);
  
  CU_ASSERT(len(a0) is 0);
  
  delete(a0);
  
}

static void test_array_at(void) {
  
  var a0 = new(Array, String, 3, $(String, "Hello"), $(String, "There"), $(String, "People"));
  
  CU_ASSERT( eq(at(a0, 0), $(String, "Hello")) );
  CU_ASSERT( eq(at(a0, 1), $(String, "There")) );
  CU_ASSERT( eq(at(a0, 2), $(String, "People")) );
  
  CU_ASSERT(at(a0, 3) is Undefined);
  CU_ASSERT(at(a0, -1) is Undefined);
  
  set(a0, 1, $(String, "Blah"));
  
  CU_ASSERT( eq(at(a0, 0), $(String, "Hello")) );
  CU_ASSERT( eq(at(a0, 1), $(String, "Blah")) );
  CU_ASSERT( eq(at(a0, 2), $(String, "People")) );
  
  set(a0, 0, $(String, "Foo"));
  set(a0, 2, $(String, "Bar"));
  
  CU_ASSERT( eq(at(a0, 0), $(String, "Foo")) );
  CU_ASSERT( eq(at(a0, 1), $(String, "Blah")) );
  CU_ASSERT( eq(at(a0, 2), $(String, "Bar")) );
  
  delete(a0);
  
}

static void test_array_iter(void) {
  
  var a0 = new(Array, String, 3, $(String, "Hello"), $(String, "There"), $(String, "People"));
  
  int counter = 0;
  
  foreach(a0, item) {
    
    switch(counter) {
      case 0: CU_ASSERT( eq(item, $(String, "Hello")) ); break;
      case 1: CU_ASSERT( eq(item, $(String, "There")) ); break;
      case 2: CU_ASSERT( eq(item, $(String, "People")) ); break;
    }
    
    counter++;
  }
  
  CU_ASSERT(counter is 3);
  
  counter = 0;
  
  foreach(a0, item0) {
    foreach(a0, item1) {
      counter++;
    }
  }
  
  CU_ASSERT(counter is 9);
  
}

static void test_array_reverse(void) {
  
  var a0 = new(Array, String, 3, $(String, "Hello"), $(String, "There"), $(String, "People"));
  var a1 = new(Array, String, 3, $(String, "People"), $(String, "There"), $(String, "Hello"));
  
  CU_ASSERT( not eq(a0, a1) );
  
  reverse(a0);
  
  CU_ASSERT( eq(a0, a1) );
  
}

static void test_table_create(void) {
  
  var t0 = new(Table, String, Int);
  put(t0, $(String, "Hello"), $(Int, 2));
  put(t0, $(String, "There"), $(Int, 5));
  
  var t1 = new(Table, String, Int);
  put(t1, $(String, "Bonjour"), $(Int, 9));
  put(t1, $(String, "Where"), $(Int, 5));
  
  var t2 = copy(t0);
  
  CU_ASSERT(t0);
  CU_ASSERT(t1);
  CU_ASSERT(t2);
  
  CU_ASSERT(t0 != t2);
  CU_ASSERT(t0 != t1);
  
  CU_ASSERT(contains(t0, $(String, "Hello")));
  CU_ASSERT(contains(t1, $(String, "Bonjour")));
  CU_ASSERT(contains(t2, $(String, "There")));
  
  assign(t2, t1);
  
  CU_ASSERT(contains(t2, $(String, "Where")));
  CU_ASSERT(contains(t2, $(String, "Bonjour")));
  CU_ASSERT(not contains(t2, $(String, "Hello")));
  CU_ASSERT(not contains(t2, $(String, "There")));
  
  delete(t0);
  delete(t1);
  delete(t2);
  
}

static void test_table_collection(void) {
  
  var t0 = new(Table, String, Int);
  put(t0, $(String, "Hello"), $(Int, 2));
  put(t0, $(String, "There"), $(Int, 5));
  
  CU_ASSERT(len(t0) is 2);
  CU_ASSERT(contains(t0, $(String, "Hello")));
  
  discard(t0, $(String, "Hello"));
  
  CU_ASSERT(len(t0) is 1);
  CU_ASSERT(not contains(t0, $(String, "Hello")));
  CU_ASSERT(contains(t0, $(String, "There")));
  
  clear(t0);
  
  CU_ASSERT(len(t0) is 0);
  CU_ASSERT(not contains(t0, $(String, "Hello")));
  CU_ASSERT(not contains(t0, $(String, "There")));
  
  delete(t0);
  
}

static void test_table_dict(void) {
  
  var t0 = new(Table, String, Int);
  put(t0, $(String, "Hello"), $(Int, 2));
  put(t0, $(String, "There"), $(Int, 5));
  
  var i0 = get(t0, $(String, "Hello"));
  var i1 = get(t0, $(String, "There"));
  
  CU_ASSERT( eq(i0, $(Int, 2)) );
  CU_ASSERT( eq(i1, $(Int, 5)) );
  
  delete(t0);
  
}

static void test_table_iter(void) {
  
  var t0 = new(Table, String, Int);
  put(t0, $(String, "Hello"), $(Int, 2));
  put(t0, $(String, "There"), $(Int, 5));
  
  int counter = 0;
  
  foreach(t0, key) {
    
    var val = get(t0, key);
    
    switch(counter) {
      case 0: CU_ASSERT( eq(key, $(String, "Hello")) ); break;
      case 1: CU_ASSERT( eq(key, $(String, "There")) ); break;
    }
    
    switch(counter) {
      case 0: CU_ASSERT( eq(val, $(Int, 2)) ); break;
      case 1: CU_ASSERT( eq(val, $(Int, 5)) ); break;
    }
    
    counter++;
  }
  
  CU_ASSERT(counter is 2);
  
}

static void test_tree_create(void) {

  var t0 = new(Tree, String, Int);
  put(t0, $(String, "Hello"), $(Int, 2));
  put(t0, $(String, "There"), $(Int, 5));
  
  var t1 = new(Tree, String, Int);
  put(t1, $(String, "Bonjour"), $(Int, 9));
  put(t1, $(String, "Where"), $(Int, 5));
  
  var t2 = copy(t0);
  
  CU_ASSERT(t0);
  CU_ASSERT(t1);
  CU_ASSERT(t2);
  
  CU_ASSERT(t0 != t2);
  CU_ASSERT(t0 != t1);
  
  CU_ASSERT(contains(t0, $(String, "Hello")));
  CU_ASSERT(contains(t1, $(String, "Bonjour")));
  CU_ASSERT(contains(t2, $(String, "There")));
  
  assign(t2, t1);
  
  CU_ASSERT(contains(t2, $(String, "Where")));
  CU_ASSERT(contains(t2, $(String, "Bonjour")));
  CU_ASSERT(not contains(t2, $(String, "Hello")));
  CU_ASSERT(not contains(t2, $(String, "There")));
  
  delete(t0);
  delete(t1);
  delete(t2);

}

static void test_tree_collection(void) {

  var t0 = new(Tree, String, Int);
  put(t0, $(String, "Hello"), $(Int, 2));
  put(t0, $(String, "There"), $(Int, 5));
  
  CU_ASSERT(len(t0) is 2);
  CU_ASSERT(contains(t0, $(String, "Hello")));
  
  discard(t0, $(String, "Hello"));
  
  CU_ASSERT(len(t0) is 1);
  CU_ASSERT(not contains(t0, $(String, "Hello")));
  CU_ASSERT(contains(t0, $(String, "There")));
  
  clear(t0);
  
  CU_ASSERT(len(t0) is 0);
  CU_ASSERT(not contains(t0, $(String, "Hello")));
  CU_ASSERT(not contains(t0, $(String, "There")));
  
  delete(t0);

}

static void test_tree_dict(void) {

  var t0 = new(Tree, String, Int);
  put(t0, $(String, "Hello"), $(Int, 2));
  put(t0, $(String, "There"), $(Int, 5));
  
  var i0 = get(t0, $(String, "Hello"));
  var i1 = get(t0, $(String, "There"));
  
  // TODO: Renable once tree is working.
  //CU_ASSERT( eq(i0, $(Int, 2)) );
  //CU_ASSERT( eq(i0, $(Int, 5)) );
  
  delete(t0);

}

static void test_tree_iter(void) {

  var t0 = new(Tree, String, Int);
  put(t0, $(String, "Hello"), $(Int, 2));
  put(t0, $(String, "There"), $(Int, 5));
  
  int counter = 0;
  
  foreach(t0, key) {
    
    var val = get(t0, key);
    
    switch(counter) {
      case 0: CU_ASSERT( eq(key, $(String, "Hello")) ); break;
      case 1: CU_ASSERT( eq(key, $(String, "There")) ); break;
    }
    
    switch(counter) {
      case 0: CU_ASSERT( eq(val, $(Int, 2)) ); break;
      case 1: CU_ASSERT( eq(val, $(Int, 5)) ); break;
    }
    
    counter++;
  }
  
  CU_ASSERT(counter is 2);

}

#define TEST_VALUES() \
var li0 = $(Int, 0); \
var li1 = $(Real, 5.0); \
var li2 = $(Int, 7); \
var li3 = $(String, "Hello"); \
var li4 = $(Real, 0.0); \
var li5 = $(String, "There"); \
var li6 = $(String, "There"); \
var dk0 = $(String, "Hello"); \
var dk1 = $(String, "There"); \
var dk2 = $(Int, 25); \
var dk3 = $(Int, 4); \
var dk4 = $(Real, 7.7); \
var dk5 = $(String, "Gravy"); \
var dv0 = $(Int, 5); \
var dv1 = $(Int, 231); \
var dv2 = $(Int, 543); \
var dv3 = $(Int, 9592); \
var dv4 = $(Int, 933); \
var dv5 = $(Real, 5.8); \
var dv6 = $(Real, 23.1); \
var dv7 = $(Real, 5.43); \
var dv8 = $(Real, 959.211); \
var dv9 = $(Real, 9.3321);

static void test_list_create(void) {
  
  TEST_VALUES();
  
  var l0 = new(List, 4, li0, li1, li2, li3);
  var l1 = new(List, 2, li4, li5);
  var l2 = copy(l0);
  
  CU_ASSERT(l0);
  CU_ASSERT(l1);
  CU_ASSERT(l2);
  
  CU_ASSERT(l0 != l1);
  CU_ASSERT(l0 != l2);
  CU_ASSERT(l1 != l2);
  
  CU_ASSERT(at(l0, 0) is li0);
  CU_ASSERT(at(l0, 2) is li2);
  CU_ASSERT(at(l1, 0) is li4);
  CU_ASSERT(at(l1, 1) is li5);
  CU_ASSERT(at(l2, 0) is li0);
  CU_ASSERT(at(l2, 1) is li1);
  
  assign(l2, l1);
  
  CU_ASSERT(at(l2, 0) is li4);
  CU_ASSERT(at(l2, 1) is li5);
  
  delete(l0);
  delete(l1);
  delete(l2);
  
}

static void test_list_eq(void) {
  
  TEST_VALUES();
  
  var l0 = new(List, 4, li0, li1, li2, li3);
  var l1 = new(List, 2, li4, li5);
  var l2 = new(List, 4, li0, li1, li2, li3);
  var l3 = new(List, 2, li0, li6);
  
  CU_ASSERT(l0 != l1);
  CU_ASSERT(l0 != l2);
  CU_ASSERT(l1 != l2);
  
  // TODO: Should 'l1' actually be equal to 'l3'?
  
  CU_ASSERT( eq(l0, l2) );
  CU_ASSERT( eq(l1, l3) );
  CU_ASSERT( neq(l0, l1) );
  CU_ASSERT( neq(l1, l2) );
  
  delete(l0);
  delete(l1);
  delete(l2);
  
}

static void test_list_collection(void) {
  
  TEST_VALUES();
  
  var l0 = new(List, 4, li0, li1, li2, li3);
  
  CU_ASSERT(len(l0) is 4);
  CU_ASSERT(contains(l0, li0));
  CU_ASSERT(contains(l0, li1));
  CU_ASSERT(contains(l0, li2));
  CU_ASSERT(contains(l0, li3));
  CU_ASSERT(contains(l0, li4));
  CU_ASSERT(not contains(l0, li5));
  
  discard(l0, li0);
  
  CU_ASSERT(len(l0) is 3);
  CU_ASSERT(not contains(l0, li0));
  CU_ASSERT(contains(l0, li1));
  CU_ASSERT(contains(l0, li2));
  CU_ASSERT(contains(l0, li3));
  CU_ASSERT(not contains(l0, li4));
  CU_ASSERT(not contains(l0, li5));
  
  clear(l0);
  
  CU_ASSERT(len(l0) is 0);
  CU_ASSERT(not contains(l0, li0));
  CU_ASSERT(not contains(l0, li1));
  CU_ASSERT(not contains(l0, li2));
  CU_ASSERT(not contains(l0, li3));
  CU_ASSERT(not contains(l0, li4));
  CU_ASSERT(not contains(l0, li5));
  
  delete(l0);
  
}

static void test_list_push(void) {
  
  TEST_VALUES();
  
  var l0 = new(List, 0);
  
  CU_ASSERT(len(l0) is 0);
  
  push(l0, li0);
  
  CU_ASSERT(len(l0) is 1);
  CU_ASSERT(at(l0, 0) is li0);
  
  push_back(l0, li1);

  CU_ASSERT(len(l0) is 2);
  CU_ASSERT(at(l0, 0) is li0);
  CU_ASSERT(at(l0, 1) is li1);
  
  push_front(l0, li2);
  
  CU_ASSERT(len(l0) is 3);
  CU_ASSERT(at(l0, 0) is li2);
  CU_ASSERT(at(l0, 1) is li0);
  CU_ASSERT(at(l0, 2) is li1);
  
  push_at(l0, li3, 1);
  
  CU_ASSERT(len(l0) is 4);
  CU_ASSERT(at(l0, 0) is li2);
  CU_ASSERT(at(l0, 1) is li3);
  CU_ASSERT(at(l0, 2) is li0);
  CU_ASSERT(at(l0, 3) is li1);
  
  pop_at(l0, 2);
  
  CU_ASSERT(len(l0) is 3);
  CU_ASSERT(at(l0, 0) is li2);
  CU_ASSERT(at(l0, 1) is li3);
  CU_ASSERT(at(l0, 2) is li1);
  
  pop_front(l0);
  
  CU_ASSERT(len(l0) is 2);
  CU_ASSERT(at(l0, 0) is li3);
  CU_ASSERT(at(l0, 1) is li1);
  
  pop_back(l0);
  
  CU_ASSERT(len(l0) is 1);
  CU_ASSERT(at(l0, 0) is li3);
  
  pop(l0);
  
  CU_ASSERT(len(l0) is 0);
  
  delete(l0);
  
}

static void test_list_at(void) {
  
  TEST_VALUES();
  
  var l0 = new(List, 4, li0, li1, li2, li3);
  
  CU_ASSERT(at(l0, 0) is li0);
  CU_ASSERT(at(l0, 1) is li1);
  CU_ASSERT(at(l0, 2) is li2);
  CU_ASSERT(at(l0, 3) is li3);
  
  CU_ASSERT(at(l0, 4) is Undefined);
  CU_ASSERT(at(l0, -1) is Undefined);
  
  set(l0, 0, li4);
  
  CU_ASSERT(at(l0, 0) is li4);
  CU_ASSERT(at(l0, 1) is li1);
  CU_ASSERT(at(l0, 2) is li2);
  CU_ASSERT(at(l0, 3) is li3);
  
  set(l0, 1, li5);
  set(l0, 2, li6);
  set(l0, 3, li0);
  
  CU_ASSERT(at(l0, 0) is li4);
  CU_ASSERT(at(l0, 1) is li5);
  CU_ASSERT(at(l0, 2) is li6);
  CU_ASSERT(at(l0, 3) is li0);
  
  delete(l0);
  
}

static void test_list_iter(void) {
  
  TEST_VALUES();
  
  var l0 = new(List, 4, li0, li1, li2, li3);
  
  int counter = 0;
  
  foreach(l0, item) {
    
    switch(counter) {
      case 0: CU_ASSERT(item is li0); break;
      case 1: CU_ASSERT(item is li1); break;
      case 2: CU_ASSERT(item is li2); break;
      case 3: CU_ASSERT(item is li3); break;
    }
    
    counter++;
  }
  
  delete(l0);
  
}

static void test_list_reverse(void) {
  
  TEST_VALUES();
  
  var l0 = new(List, 4, li0, li1, li2, li3);
  var l1 = new(List, 4, li3, li2, li1, li0);

  CU_ASSERT(neq(l0, l1));
  
  reverse(l1);
  
  CU_ASSERT(eq(l0, l1));
  
  delete(l0);
  delete(l1);
  
}

static void test_dictionary_create(void) {
  
  TEST_VALUES();
  
  var d0 = new(Dictionary);
  put(d0, dk0, dv0);
  put(d0, dk1, dv5);
  put(d0, dk2, dv9);
  
  var d1 = new(Dictionary);
  put(d1, dk3, dv2);
  put(d1, dk4, dv3);
  put(d1, dk5, dv4);
  
  var d2 = copy(d0);
  
  CU_ASSERT(d0);
  CU_ASSERT(d1);
  CU_ASSERT(d2);
  
  CU_ASSERT(d0 != d1);
  CU_ASSERT(d0 != d2);
  CU_ASSERT(d1 != d2);
  
  CU_ASSERT(contains(d0, dk0));
  CU_ASSERT(contains(d0, dk1));
  CU_ASSERT(contains(d0, dk2));
  
  CU_ASSERT(contains(d1, dk3));
  CU_ASSERT(contains(d1, dk4));
  CU_ASSERT(contains(d1, dk5));
  
  CU_ASSERT(contains(d2, dk0));
  CU_ASSERT(contains(d2, dk1));
  CU_ASSERT(contains(d2, dk2));
  
  assign(d2, d1);
  
  CU_ASSERT(contains(d2, dk3));
  CU_ASSERT(contains(d2, dk4));
  CU_ASSERT(contains(d2, dk5));
  
  delete(d0);
  delete(d1);
  delete(d2);
  
}

static void test_dictionary_collection(void) {
  
  TEST_VALUES();
  
  var d0 = new(Dictionary);
  put(d0, dk0, dv0);
  put(d0, dk1, dv5);
  put(d0, dk2, dv9);
  
  CU_ASSERT(len(d0) is 3);
  CU_ASSERT(contains(d0, dk0));
  CU_ASSERT(contains(d0, dk1));
  CU_ASSERT(contains(d0, dk2));
  
  discard(d0, dk0);
  
  CU_ASSERT(len(d0) is 2);
  CU_ASSERT(not contains(d0, dk0));
  CU_ASSERT(contains(d0, dk2));
  CU_ASSERT(contains(d0, dk2));

  clear(d0);
  
  CU_ASSERT(len(d0) is 0);
  CU_ASSERT(not contains(d0, dk0));
  CU_ASSERT(not contains(d0, dk2));
  CU_ASSERT(not contains(d0, dk2));
  
  delete(d0);
  
}

static void test_dictionary_iter(void) {
  
  TEST_VALUES();
  
  var d0 = new(Dictionary);
  put(d0, dk0, dv0);
  put(d0, dk1, dv5);
  put(d0, dk2, dv9);
  
  int counter = 0;
  
  foreach(d0, key) {
  
    var val = get(d0, key);
    
    switch(counter) {
      case 0: CU_ASSERT(key is dk0); break;
      case 1: CU_ASSERT(key is dk1); break;
      case 2: CU_ASSERT(key is dk2); break;
    }
    
    switch(counter) {
      case 0: CU_ASSERT(val is dv0); break;
      case 1: CU_ASSERT(val is dv5); break;
      case 2: CU_ASSERT(val is dv9); break;
    }
    
    counter++;
  }
  
  CU_ASSERT(counter is 3);
  
}

static void test_dictionary_dict(void) {
  
  TEST_VALUES();
  
  var d0 = new(Dictionary);
  put(d0, dk0, dv0);
  put(d0, dk1, dv5);
  put(d0, dk2, dv9);
  
  CU_ASSERT(get(d0, dk0) is dv0);
  CU_ASSERT(get(d0, dk1) is dv5);
  CU_ASSERT(get(d0, dk2) is dv9);
  
  delete(d0);
  
}

static void test_map_create(void) {
  
  TEST_VALUES();
  
  var d0 = new(Map);
  put(d0, dk0, dv0);
  put(d0, dk1, dv5);
  put(d0, dk2, dv9);
  
  var d1 = new(Map);
  put(d1, dk3, dv2);
  put(d1, dk4, dv3);
  put(d1, dk5, dv4);
  
  var d2 = copy(d0);
  
  CU_ASSERT(d0);
  CU_ASSERT(d1);
  CU_ASSERT(d2);
  
  CU_ASSERT(d0 != d1);
  CU_ASSERT(d0 != d2);
  CU_ASSERT(d1 != d2);
  
  CU_ASSERT(contains(d0, dk0));
  CU_ASSERT(contains(d0, dk1));
  CU_ASSERT(contains(d0, dk2));
  
  CU_ASSERT(contains(d1, dk3));
  CU_ASSERT(contains(d1, dk4));
  CU_ASSERT(contains(d1, dk5));
  
  CU_ASSERT(contains(d2, dk0));
  CU_ASSERT(contains(d2, dk1));
  CU_ASSERT(contains(d2, dk2));
  
  assign(d2, d1);
  
  CU_ASSERT(contains(d2, dk3));
  CU_ASSERT(contains(d2, dk4));
  CU_ASSERT(contains(d2, dk5));
  
  delete(d0);
  delete(d1);
  delete(d2);
  
}

static void test_map_collection(void) {
  
  TEST_VALUES();
  
  var d0 = new(Map);
  put(d0, dk0, dv0);
  put(d0, dk1, dv5);
  put(d0, dk2, dv9);
  
  CU_ASSERT(len(d0) is 3);
  CU_ASSERT(contains(d0, dk0));
  CU_ASSERT(contains(d0, dk1));
  CU_ASSERT(contains(d0, dk2));
  
  discard(d0, dk0);
  
  CU_ASSERT(len(d0) is 2);
  CU_ASSERT(not contains(d0, dk0));
  CU_ASSERT(contains(d0, dk2));
  CU_ASSERT(contains(d0, dk2));

  clear(d0);
  
  CU_ASSERT(len(d0) is 0);
  CU_ASSERT(not contains(d0, dk0));
  CU_ASSERT(not contains(d0, dk2));
  CU_ASSERT(not contains(d0, dk2));
  
  delete(d0);
  
}

static void test_map_iter(void) {
  
  TEST_VALUES();
  
  var d0 = new(Map);
  put(d0, dk0, dv0);
  put(d0, dk1, dv5);
  put(d0, dk2, dv9);
  
  int counter = 0;
  
  foreach(d0, key) {
  
    var val = get(d0, key);
    
    switch(counter) {
      case 0: CU_ASSERT(key is dk0); break;
      case 1: CU_ASSERT(key is dk1); break;
      case 2: CU_ASSERT(key is dk2); break;
    }
    
    switch(counter) {
      case 0: CU_ASSERT(val is dv0); break;
      case 1: CU_ASSERT(val is dv5); break;
      case 2: CU_ASSERT(val is dv9); break;
    }
    
    counter++;
  }
  
  CU_ASSERT(counter is 3);
  
}

static void test_map_dict(void) {
  
  TEST_VALUES();
  
  var d0 = new(Map);
  put(d0, dk0, dv0);
  put(d0, dk1, dv5);
  put(d0, dk2, dv9);
  
  CU_ASSERT(get(d0, dk0) is dv0);
  CU_ASSERT(get(d0, dk1) is dv5);
  CU_ASSERT(get(d0, dk2) is dv9);
  
  delete(d0);
  
}

static void test_file_create(void) {
  
  TEST_VALUES();
  
  var f0 = new(File, "test.bin", "w"); 
  var f1 = $(File, NULL);
  var f2 = copy(f1);
  
  CU_ASSERT(f0);
  CU_ASSERT(f1);
  CU_ASSERT(f2);
  
  CU_ASSERT(f0 != f1);
  CU_ASSERT(f0 != f2);
  CU_ASSERT(f1 != f2);
  
  assign(f2, f0);
  
  CU_ASSERT(f0);
  CU_ASSERT(f1);
  CU_ASSERT(f2);
  
  CU_ASSERT(f0 != f1);
  CU_ASSERT(f0 != f2);
  CU_ASSERT(f1 != f2);
  
  delete(f0);
  delete(f2);
  
}

static char testoutput1[] = "This is a test\n";
static char testoutput2[] = "This is a sample\n";
static char testinput[512];

static void test_file_read(void) {
  
  var f0 = $(File, NULL);
  
  open(f0, "test.txt", "w");
  write(f0, testoutput1, sizeof(testoutput1));
  close(f0);  
  
  open(f0, "test.txt", "r");
  read(f0, testinput, sizeof(testoutput1));
  close(f0);
  
  CU_ASSERT_STRING_EQUAL(testinput, testoutput1);
  
  open(f0, "test.txt" , "w");
  
  put(f0, String, $(String, "This is an apple\n"));
  seek(f0, 9, SEEK_SET );
  
  CU_ASSERT(tell(f0) is 9);
  CU_ASSERT((var)eof(f0) is False);
  
  flush(f0);
  
  write(f0, " sam", 4);
  
  close(f0);
  
  open(f0, "test.txt", "r");
  read(f0, testinput, sizeof(testoutput2));
  close(f0);
  
  CU_ASSERT_STRING_EQUAL(testinput, testoutput2);
  
}

static void test_file_dict(void) {
  
  var f = $(File, NULL);
  
  open(f, "test.bin", "w");
    
    put(f, String, $(String, "Hello"));
    put(f, Int, $(Int, 1));
    put(f, Int, $(Int, 22));
  
  close(f);
  
  open(f, "test.bin", "r");
    
    var string = get(f, String);
    var first = get(f, Int);
    var second = get(f, Int);
    
    CU_ASSERT( eq(string, $(String, "Hello")) );
    CU_ASSERT( eq(first, $(Int, 1)) );
    CU_ASSERT( eq(second, $(Int, 22)) );
    
    delete(string);
    delete(first);
    delete(second);
    
  close(f);
  
}

int init_data_suite(void) {
  return 0;
}

int build_data_suite(CU_pSuite suite) {

  if (suite is None) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  if ((CU_add_test(suite, "Bool Ord", test_bool_ord)              is None) or 
      (CU_add_test(suite, "Bool Hash", test_bool_hash)            is None) or 
      (CU_add_test(suite, "Bool As C-types", test_bool_asctypes)  is None) or 
      
      (CU_add_test(suite, "Char Create", test_char_create)        is None) or 
      (CU_add_test(suite, "Char Ord", test_char_ord)              is None) or 
      (CU_add_test(suite, "Char Hash", test_char_hash)            is None) or 

      (CU_add_test(suite, "Int Create", test_int_create)          is None) or 
      (CU_add_test(suite, "Int Ord", test_int_ord)                is None) or 
      (CU_add_test(suite, "Int Hash", test_int_hash)              is None) or 
      (CU_add_test(suite, "Int Num", test_int_num)                is None) or 
      (CU_add_test(suite, "Int Parse", test_int_parse)            is None) or 
      
      (CU_add_test(suite, "Real Create", test_real_create)        is None) or 
      (CU_add_test(suite, "Real Ord", test_real_ord)              is None) or 
      (CU_add_test(suite, "Real Hash", test_real_hash)            is None) or 
      (CU_add_test(suite, "Real Num", test_real_num)              is None) or 
      (CU_add_test(suite, "Real Parse", test_real_parse)          is None) or 
      
      (CU_add_test(suite, "String Create", test_string_create)          is None) or 
      (CU_add_test(suite, "String Ord", test_string_ord)                is None) or 
      (CU_add_test(suite, "String Collection", test_string_collection)  is None) or 
      (CU_add_test(suite, "String Hash", test_string_hash)              is None) or 
      (CU_add_test(suite, "String Parse", test_string_parse)            is None) or 
      (CU_add_test(suite, "String Reverse", test_string_reverse)        is None) or 
      
      (CU_add_test(suite, "Array Create", test_array_create)            is None) or 
      (CU_add_test(suite, "Array Equality", test_array_eq)              is None) or
      (CU_add_test(suite, "Array Collection", test_array_collection)    is None) or
      (CU_add_test(suite, "Array Push", test_array_push)                is None) or
      (CU_add_test(suite, "Array At", test_array_at)                    is None) or
      (CU_add_test(suite, "Array Iter", test_array_iter)                is None) or
      (CU_add_test(suite, "Array Reverse", test_array_reverse)          is None) or
      
      (CU_add_test(suite, "Table Create", test_table_create)            is None) or 
      (CU_add_test(suite, "Table Collection", test_table_collection)    is None) or 
      (CU_add_test(suite, "Table Dict", test_table_dict)                is None) or 
      (CU_add_test(suite, "Table Iter", test_table_iter)                is None) or 
      
      (CU_add_test(suite, "Tree Create", test_tree_create)              is None) or 
      (CU_add_test(suite, "Tree Collection", test_tree_collection)      is None) or 
      (CU_add_test(suite, "Tree Dict", test_tree_dict)                  is None) or 
      (CU_add_test(suite, "Tree Iter", test_tree_iter)                  is None) or
      
      (CU_add_test(suite, "List Create", test_list_create)              is None) or 
      (CU_add_test(suite, "List Equality", test_list_eq)                is None) or
      (CU_add_test(suite, "List Collection", test_list_collection)      is None) or
      (CU_add_test(suite, "List Push", test_list_push)                  is None) or
      (CU_add_test(suite, "List At", test_list_at)                      is None) or
      (CU_add_test(suite, "List Iter", test_list_iter)                  is None) or
      (CU_add_test(suite, "List Reverse", test_list_reverse)            is None) or
      
      (CU_add_test(suite, "Dictionary Create", test_dictionary_create)          is None) or 
      (CU_add_test(suite, "Dictionary Collection", test_dictionary_collection)  is None) or 
      (CU_add_test(suite, "Dictionary Dict", test_dictionary_dict)              is None) or 
      (CU_add_test(suite, "Dictionary Iter", test_dictionary_iter)              is None) or 
      
      (CU_add_test(suite, "Map Create", test_map_create)          is None) or 
      (CU_add_test(suite, "Map Collection", test_map_collection)  is None) or 
      (CU_add_test(suite, "Map Dict", test_map_dict)              is None) or 
      (CU_add_test(suite, "Map Iter", test_map_iter)              is None) or
      
      (CU_add_test(suite, "File Create", test_file_create)        is None) or 
      (CU_add_test(suite, "File Read/Write", test_file_read)      is None) or 
      (CU_add_test(suite, "File Dict", test_file_dict)            is None))
  {
    CU_cleanup_registry();
    return CU_get_error();
  }

  return 0;
}