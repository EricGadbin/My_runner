/*
** EPITECH PROJECT, 2017
** Project my_runner Testing
** File description:
** Unit Testing Project my_runner
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <ctype.h>
#include "my.h"

void main_redirect_stdout(void)
{
	cr_redirect_stdout();
}

Test(my_runner, Return_Value_Test)
{
	cr_assert_eq("Function to test()", "Int Output..");
}
