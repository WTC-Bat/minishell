# minishell

0	-	Norm

0	-	SHLVL=2 ???


?	-	if arguments to command contain ';', an error will occur

FIXED	-	ft_strequ might be able to be improved

FIXED	-	SEGFAULT - two or more consecutive ';' ("echo ;;")

FIXED	-	Error when (multi?) command ends with semi-colon

FIXED	-	'inner' quotes don't work

FIXED?	-	Memory leaks. Check within functions pertaining to semicolon funcs and
			sort quote funcs

FIXED		-	quote chars placed directly after a closing quote will be printed
			[echo "Cheese"''	=	prints: Cheese'']

FIXED		-	quotes not separated by a space are considered part of the string
			[echo Cheese''	=	prints: Cheese'']
			[SEE: msh_sort_quote.c -> get_sorted() -> wstart + wend]
			[? set_start_end() ?]

FIXED		-	single quote before string will print string
			[echo "Cheese	=	prints: Cheese]
			[echo "Cheese ''	=	prints: Cheese '']

FIXED		-	single quote after string will print string and quote
			[echo Cheese"	=	prints: Cheese"]

0		-	a string after a quoted string will be separated by a spce
			[echo "Cheese"Crackers	=	prints: Cheese Crackers]
			[It should print: CheeseCrackers]

0		-	a string before a quoted string will result in the quotes remaining
			[echo Cheese"Crackers"	=	prints: Cheese"Crackers"]
			[It should print: CheeseCrackers]

FIXED		-	[echo "Cheese" and	=	SEGFAULT]
			(with or without a trailing space)
			(only if "Cheese" is quoted)

FIXED		-	NORME:	msh_sort_quote.c -> set_start_end()	has 5 parameters,
						only 4 allowed
						msh_sort_quote.c -> get_sorted()	has 28 lines

FIXED	-	function line length, headers!
			-	msh_sort_quote.c
				-	msh_sort_quote()
					-	Lines
					-	Variables
				-	wdcnt()
					-	Lines - FIXED
			-	msh_cmd_split.c
				-	msh_cmd_split()
					-	Variables - FIXED

FIXED	-	incomplete words will still run command with closest match
			-	(exi	- will run exit)


//////
BRANCH
//////
THIS BRANCH HAS NO SIGNIFICANT CHANGES TO "quote"

///////
MYTRACE
///////

0	-	SEMI-COLON ENDING TRACE:	(FOUND!)
		-	file:	minishell.c
			-	function:	msh_cmd_split()
		-	file:	msh_cmd_split.c
			-	function:	msh_cmd_split()


0	-	COMPLICATIONS WHEN USING MULTI-COMMANDS !!!!
		- start at handle_multi_command -?
		- msh_cmd_split?
		- MANUAL_TRACE:	(FOUND!)
			-	(1)
			-	file:	msh_sort_quote.c
				-	function:	msh_sort_quote()
				-	variable:	input;
			-	(2)
			-	file:	minishell.c
				-	function:	handle_multi_command()
				-	variable:	args;/cmds->content;
			-	(3)
			-	file:	msh_cmd_split.c
				-	function:	msh_cmd_split()
				-	(???)
				-	(error in msh_cmd_split?)
