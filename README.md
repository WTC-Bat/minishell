# minishell

0	-	Norm

0	-	SHLVL=2 ???



0	-	Think I need to rework the 'remove_var' function in 'msh_bltn_unsetenv'

0	-	if arguments to command contain ';', an error will occur

0	-	ft_strequ might be able to be improved


0	-	COMPLICATIONS WHEN USING MULTI-COMMANDS !!!!
		- start at handle_multi_command -?
		- msh_cmd_split?
		- MANUAL_TRACE:
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
