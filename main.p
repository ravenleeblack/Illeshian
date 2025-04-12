start_link @main.p @line 0
num main manager: num argc, mark_ptr[mark table: argv[]]`
{
    hold num: test;

    check: test > 0`
    {
        assign: test = 2;
    } pass_arg: 0`;


} yield: 0`;
end_link