// This demonstrates the use of static keyword in the C context...
// I learned something new about compilation units too...

// #include <file2.cpp>
// If you include the above file, file1.cpp and file2.cpp will no longer form
//  two separate compilation units.
// Instead, they'll merge into one and render the keyword static useless.

extern void foo ();     // This would work since it's not marked static in file2.cpp

extern void bar ();     // This would not work since it's marked static in file2.cpp

int main ()
{
    foo();
    bar();      // This would result in linker error as bar is marked static in file2.cpp

    return 0;
}
