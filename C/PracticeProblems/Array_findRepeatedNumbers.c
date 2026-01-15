// WAP a program to check whether any of the digits in a number apprears more than once

// #include<stdio.h>

// int main()
// {
//    int number=628768927;
//    int rem, rem1, temp;
//    temp = number/10;

//    while(number != 0)
//    {
//     rem = number%10;
//     while(temp != 0){
//         rem1 = temp % 10;
//         if(rem == rem1){
//             printf("%d Yes\n", rem);

//         }      
//         else printf("No\n");
//         temp /= 10;
//     }
//     number /= 10;
//     temp = number/10;
//    }
//    return 0;
// }

#include<stdio.h>

int main()
{
    int number = 98347299;
    int seen[10] = {0};
    int rem;

    while(number != 0)
    {
        rem = number%10;
        if(seen[rem] != 0){
            printf("%d Yes\n", rem);
            break;
        }
        seen[rem] = rem;
        number /= 10;
    }
    return 0;
}