//1 . you can use static_cast to perform explicit conversions that are supported by the language. e.g. if you write an arithmetic operatons where you have defined
//variables as ints and you perform a divide operation where you want a floating point division to takeplace, then you can static_cast one of the two operands
// to a double.
// 2. you can use static_cast() to perform explicit conversions that are allowed because of userdefined constructors or conversion routines.