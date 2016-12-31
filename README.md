# minishell

0	-	Check 'cd's' memory usage

0	-	Fix cd after cd'ing to /. After cd'ing to /, the next path cd'd
		to will be //new_dir, it should just be /new_dir

0	-	Norm

0	-	cd'ing to ../ takes us back two folders instead of one
		[RE-WRITE msh_cd AND/OR msh_cd_navigate]
		[ALSO HAS LEAKS]

0	-	SHLVL=2 ???

0	-	Fixup Makefile (linker and such). '#include "libft.h"' instead of
		'#include "../libft/libft.h"' and for minishell.h

0	-
