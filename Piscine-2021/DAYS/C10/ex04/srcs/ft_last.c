/* More of the command "who" than "last */

// https://youtu.be/JMcgrq173Ow?t=2339

#include <stdio.h>
#include <utmpx.h>
#include <sys/time.h>

void	display_entry_time(long time)
{
	struct tm *ltime;
	char 	buff[64];

	ltime = localtime(&time);
	strftime(buff, sizeof(buff), "%Y-%m-%d %H:%M:%S", ltime);
	printf("%s - ", buff);

}

void	desplay_entry(struct utmpx *entry)
{
	printf("%s - ", entry->ut_user);
	printf("%s - ", entry->ut_line);
	display_entry_time(entry->ut_tv.tv_sec);
	printf("%s\n", entry->ut_host);
	//printf("%s - ", entry->ut_id);
	//printf("%d - ", entry->ut_pid);
	//printf("%d - ", SHUTDOWN_TIME);
}

int	main(void)
{
	struct utmpx *entry;

	while ((entry = getutxent()) != NULL)
	{
		///printf("%d\n", USER_PROCESS);
		if (entry->ut_type != USER_PROCESS)
			continue;
		desplay_entry(entry);
	}
	return (0);
}
