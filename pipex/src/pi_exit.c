#include "pipex.h"

void	pi_exit(t_pipeinfo *info)
{
	pi_freeinfo(info);
	exit(1);
}
