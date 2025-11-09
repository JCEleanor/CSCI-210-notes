#include <stdio.h>

struct Person
{
    char name[64];
    int age;
};

int main()
{
    char s[10] = "Trip";
    printf("Sizeof char: %zu\n", sizeof(char));
    struct Person people[10];
    struct Person *p_person = people;

    int i = 0;
    for (i = 0; i < 100; i++)
    {
        p_person->age = 0;

        // this is wrong.
        //  objdump -d pointer-arithmatic -Mintel | less
        // p_person += sizeof(struct Person);
        p_person += 1;
    }
}
