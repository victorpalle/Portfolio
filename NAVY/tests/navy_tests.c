/*
** EPITECH PROJECT, 2020
** SEMESTRE 1
** File description:
** navy_tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my_navy.h"

void redirect_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
    cr_redirect_stdin();
}

void redirect_signal(void)
{
    SIGUSR1;
    SIGUSR2;
    SIGSEGV;
    SIGQUIT;
    SIGINT;
}

Test(helper, navy_tests, .init = redirect_std)
{
    int ac = 2;
    char *av[] = {"./navy", "-h"};

    parser(ac, av);

    cr_assert_stdout_eq_str(
    "  USAGE\n"
    "/Player 1/   ./navy [navy positions]...\n\n"
    "/Player 2/   ./nave [player pid]..."
    "[navy positions]...\n\n"
    "  DESCRIPTION\n"
    "[player pid]\n"
    "pid of the ennemy player\n"
    "[navy positions] (as a file)\n"
    "file representing the positions of the ships\n"
    "the file must contains three parameters :\n"
    "LENGTH   FIRST SQUARE    LAST SQUARE\n"
    "note : the board must have 4 ships from size 2 to size 5\n");
}

Test(navy_return_value, navy_tests, .init = redirect_std)
{
    int ac = 2;
    char *av[] = {"./navy", "i'm not a file"};

    parser(ac, av);

    cr_assert_stdout_eq_str("unknown file\n");
}

Test(navy_wrong_pid, navy_tests, .init = redirect_std)
{
    int ac = 3;
    char *av[] = {"./navy", "ZERTYUI", "pos2"};
    int return_value;

    return_value = parser(ac, av);

    cr_assert_eq(return_value, 84);
}

Test(navy_wrong_pid_2, navy_tests, .init = redirect_std)
{
    int ac = 3;
    char *av[] = {"./navy", "-45678", "pos2"};
    int return_value;

    return_value = parser(ac, av);

    cr_assert_eq(return_value, 84);
}

Test(navy_less_args, navy_tests, .init = redirect_std)
{
    int ac = 1;
    char *av[] = {"./navy"};
    int return_value;

    return_value = parser(ac, av);

    cr_assert_eq(return_value, 0);
}

Test(navy_toomuch_args, navy_tests, .init = redirect_std)
{
    int ac = 4;
    char *av[] = {"./navy", "pos1", "pos2", "pos3"};

    cr_assert_null(parser(ac, av));
}

Test(navy_win_condition, navy_tests, .init = redirect_std)
{
    navy_t s;

    s.win = 14;

    win(&s);

    cr_assert_stdout_eq_str("\nI won\n\n");
}

Test(navy_win_condition_else, navy_tests, .init = redirect_std)
{
    navy_t s;

    s.win = 13;

    win(&s);

    cr_assert_stdout_eq_str("\nEnemy won\n\n");
}

Test(navy_isnum, navy_tests, .init = redirect_std)
{
    char num = '2';
    int return_value;

    return_value = isnum(num);

    cr_assert_eq(return_value, 1);
}

Test(navy_isnum_else, navy_tests, .init = redirect_std)
{
    char num = 'z';
    int return_value;

    return_value = isnum(num);

    cr_assert_eq(return_value, 0);
}

Test(navy_is_validmessage, navy_tests, .init = redirect_std)
{
    char *message = "A2";
    int return_value;

    return_value = is_validmessage(message);

    cr_assert_eq(return_value, 0);
}

Test(navy_is_validmessage_else, navy_tests, .init = redirect_std)
{
    char *message = "Y9";
    int return_value;

    return_value = is_validmessage(message);

    cr_assert_eq(return_value, 0);
}

Test(navy_st_message_ptwo, navy_tests, .init = redirect_std)
{
    print_first_message_player_two();

    cr_assert_stdout_neq_str("my_pid: 0\nsuccessfully connected\n");
}

Test(navy_fill_map, navy_tests, .init = redirect_std)
{
    char **return_value;
    char *map = ".................................................."
    "..............";

    return_value = fill_map();

    cr_assert_neq(return_value, map);
}

Test(navy_error_syntax, navy_tests, .init = redirect_std)
{
    int return_value;
    char *map = "2:B1:B2\n3:C1:C3\n4:D1:D4\n5:E1;E5";

    return_value = check_buffer(map);

    cr_assert_eq(return_value, 84);
}

Test(navy_error_letter, navy_tests, .init = redirect_std)
{
    int return_value;
    char *map = "2:B1:B2\n3:Z1:C3\n4:D1:D4\n5:E1:E5";

    return_value = check_buffer(map);

    cr_assert_eq(return_value, 84);
}

Test(navy_error_number, navy_tests, .init = redirect_std)
{
    int return_value;
    char *map = "2:B1:B2\n3:C9:C3\n4:D1:D4\n5:E1;E5";

    return_value = check_buffer(map);

    cr_assert_eq(return_value, 84);
}

Test(navy_chekcerror_syntax, navy_tests, .init = redirect_std)
{
    int return_value;
    char *map = "2:B1:B2\n3:C1:C3\n4:D1:D4\n5:E1;E5";

    return_value = check_syntax(map);

    cr_assert_eq(return_value, 84);
}

Test(navy_checkerror_letter, navy_tests, .init = redirect_std)
{
    int return_value;
    char *map = "2:B1:B2\n3:Z1:C3\n4:D1:D4\n5:E1:E5";

    return_value = check_letters(map);

    cr_assert_eq(return_value, 84);
}

Test(navy_checkerror_letterbis, navy_tests, .init = redirect_std)
{
    int return_value;
    char *map = "2:B1:B2\n3:C9:Z3\n4:D1:D4\n5:E1:E5";

    return_value = check_letters_bis(map);

    cr_assert_eq(return_value, 84);
}

Test(navy_checksyntax, navy_tests, .init = redirect_std)
{
    int return_value;
    char *map = "2;B1:B2\n3:C1:C3\n4:D1:D4\n5:D1:E5";

    return_value = check_syntax(map);

    cr_assert_eq(return_value, 84);
}

Test(navy_checksyntax_2, navy_tests, .init = redirect_std)
{
    int return_value;
    char *map = "2:B1;B2\n3:C1:C3\n4:D1:D4\n5:D1:E5";

    return_value = check_syntax(map);

    cr_assert_eq(return_value, 84);
}

Test(navy_checksyntax_3, navy_tests, .init = redirect_std)
{
    int return_value;
    char *map = "4:B1;B2\n3:C1:C3\n4:D1:D4\n5:D1:E5";

    return_value = check_syntax(map);

    cr_assert_eq(return_value, 84);
}

Test(navy_checkerror_numbers_1, navy_tests, .init = redirect_std)
{
    int return_value;
    char *map = "2:B1:B2\n3:C1:C3\n4:D1:D4\n5:E9:E5";

    return_value = check_numbers(map);

    cr_assert_eq(return_value, 84);
}

Test(navy_checkerror_numbers_2, navy_tests, .init = redirect_std)
{
    int return_value;
    char *map = "2:C0:C2\n3:D1:D3\n4:D1:D4\n5:E1:E5";

    return_value = check_numbers(map);

    cr_assert_eq(return_value, 84);
}

Test(navy_checkerror_numbers_3, navy_tests, .init = redirect_std)
{
    int return_value;
    char *map = "2:B1:B2\n3:C9:C3\n4:D1:D4\n5:E1:E5";

    return_value = check_numbers(map);

    cr_assert_eq(return_value, 84);
}

Test(navy_checkerror_numbers_4, navy_tests, .init = redirect_std)
{
    int return_value;
    char *map = "2:B1:B2\n3:C1:C3\n4:D0:D4\n5:E1:E5";

    return_value = check_numbers(map);

    cr_assert_eq(return_value, 84);
}

Test(navy_checkerror_numversbis_1, navy_tests, .init = redirect_std)
{
    int return_value;
    char *map = "2:B1:B0\n3:C1:C3\n4:D1:D4\n5:E1:E5";

    return_value = check_numbers_bis(map);

    cr_assert_eq(return_value, 84);
}

Test(navy_checkerror_numbers_bis_2, navy_tests, .init = redirect_std)
{
    int return_value;
    char *map = "2:B1:B2\n3:C1:C0\n4:D1:D4\n5:E1:E5";

    return_value = check_numbers_bis(map);

    cr_assert_eq(return_value, 84);
}

Test(navy_checkerror_numbersbis_3, navy_tests, .init = redirect_std)
{
    int return_value;
    char *map = "2:B1:B2\n3:C1:C3\n4:D1:D0\n5:E1:E5";

    return_value = check_numbers_bis(map);

    cr_assert_eq(return_value, 84);
}

Test(navy_checkerror_numbersbis_4, navy_tests, .init = redirect_std)
{
    int return_value;
    char *map = "2:B1:B2\n3:C1:C3\n4:D1:D4\n5:E1:E0";

    return_value = check_numbers_bis(map);

    cr_assert_eq(return_value, 84);
}

Test(navy_checkerror_letters_1, navy_tests, .init = redirect_std)
{
    int return_value;
    char *map = "2:Z1:B2\n3:C1:C3\n4:D1:D4\n5:E1:E5";

    return_value = check_letters(map);

    cr_assert_eq(return_value, 84);
}

Test(navy_checkerror_letters_2, navy_tests, .init = redirect_std)
{
    int return_value;
    char *map = "2:B1:B2\n3:Z1:C3\n4:D1:D4\n5:E1:E5";

    return_value = check_letters(map);

    cr_assert_eq(return_value, 84);
}

Test(navy_checkerror_letters_3, navy_tests, .init = redirect_std)
{
    int return_value;
    char *map = "2:B1:B2\n3:C1:C3\n4:Z1:D4\n5:E1:E5";

    return_value = check_letters(map);

    cr_assert_eq(return_value, 84);
}

Test(navy_checkerror_letter_4, navy_tests, .init = redirect_std)
{
    int return_value;
    char *map = "2:B1:B2\n3:C1:C3\n4:D1:D4\n5:Z1:E5";

    return_value = check_letters(map);

    cr_assert_eq(return_value, 84);
}

Test(navy_checkerror_lettersbis_1, navy_tests, .init = redirect_std)
{
    int return_value;
    char *map = "2:B1:Z2\n3:C1:C3\n4:D1:D4\n5:E1:E5";

    return_value = check_letters_bis(map);

    cr_assert_eq(return_value, 84);
}

Test(navy_checkerror_lettersbis_2, navy_tests, .init = redirect_std)
{
    int return_value;
    char *map = "2:B1:B2\n3:C1:Z3\n4:D1:D4\n5:E1:E5";

    return_value = check_letters_bis(map);

    cr_assert_eq(return_value, 84);
}

Test(navy_checkerror_lettersbis_3, navy_tests, .init = redirect_std)
{
    int return_value;
    char *map = "2:B1:B2\n3:C1:C3\n4:D1:Z4\n5:E1:E5";

    return_value = check_letters_bis(map);

    cr_assert_eq(return_value, 84);
}

Test(navy_checkerror_lettersbis_4, navy_tests, .init = redirect_std)
{
    int return_value;
    char *map = "2:B1:B2\n3:C1:C3\n4:D1:D4\n5:E1:Z5";

    return_value = check_letters_bis(map);

    cr_assert_eq(return_value, 84);
}

Test(navy_checkbuffer, navy_tests, .init = redirect_std)
{
    int return_value;
    char *map = "4:B1:C2\n3:C1:C3\n4:D1:D4\n5:E1:E5";

    return_value = check_buffer(map);

    cr_assert_eq(return_value, 84);
}

Test(navy_checkbuffer_2, navy_tests, .init = redirect_std)
{
    int return_value;
    char *map = "2:B1:Z2\n3:C1:C3\n4:D1:D4\n5:E1:E5";

    return_value = check_buffer(map);

    cr_assert_eq(return_value, 84);
}

Test(navy_checkbuffer_3, navy_tests, .init = redirect_std)
{
    int return_value;
    char *map = "4:B1:C2\n3:C1:C9\n4:D1:D4\n5:E1:E5";

    return_value = check_buffer(map);

    cr_assert_eq(return_value, 84);
}

Test(navy_print_map, navy_tests, .init = redirect_std)
{
    char *map[] = {"........\n", "........\n", "........\n", "........\n",
    "........\n", "........\n", "........\n", "........\n"};
    char *map_filled = "\n |A B C D E F G H\n-+---------------\n"
    "1|. . . . . . . . \n2|. . . . . . . . \n3|. . . . . . . . \n"
    "4|. . . . . . . . \n5|. . . . . . . . \n6|. . . . . . . . \n"
    "7|. . . . . . . . \n8|. . . . . . . . \n";

    print_map(map);

    cr_assert_stdout_eq_str(map_filled);
}