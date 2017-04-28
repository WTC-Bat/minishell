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

0		-	quote chars placed directly after a closing quote will be printed
			[echo "Cheese"''	=	prints: Cheese'']

0		-	single quote before string will print string
			[echo "Cheese	=	prints: Cheese]

0		-	single quote after string will print string and quote
			[echo Cheese"	=	prints: Cheese"]

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



//////////
MYTRACE
//////////

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
