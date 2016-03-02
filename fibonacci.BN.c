/* fibonacci-BN.c - Created by iohzrd - 2016 */

#include<stdio.h>
#include<gmp.h>

mpz_t fn, fn_1, fn_2, iterations, limit;

static mpz_t *next_fibonacci_numbers()
{
    mpz_add(fn, fn_1, fn_2);
    mpz_set(fn_2, fn_1);
    mpz_set(fn_1, fn);

    return (void *)fn;
}

int main()
{
    mpz_init (fn);
    mpz_init (fn_1);
    mpz_init_set_ui (fn_2 ,1);
    mpz_init_set_ui (iterations, 1);
    mpz_init (limit);

	  printf("How many fibonacci numbers to print? ");
	  gmp_scanf("%Zd", limit);

    while(mpz_cmp(limit, iterations) == 1)
    {
        gmp_printf("%Zd\n", next_fibonacci_numbers());
        mpz_add_ui(iterations, iterations, 1);
    }

    mpz_clear(fn);
    mpz_clear(fn_1);
    mpz_clear(fn_2);
    mpz_clear(limit);
    mpz_clear(iterations);
}
