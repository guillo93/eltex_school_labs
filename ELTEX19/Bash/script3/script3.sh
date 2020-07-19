#!/bin/sh

#bluetooth body work in progress

PATH=/sbin:/bin:/usr/sbin:/usr/bin
DESC=script3

DAEMON=/usr/sbin/script3

test -f $DAEMON || exit 0

# FIXME: any of the sourced files may fail if/with syntax errors
test -f /etc/default/script3 && . /etc/default/script3

. /lib/lsb/init-functions

do_login()
{
	#sudo touch /etc/profile.d/script3login.sh;
	#chmod +x /etc/profile.d/script3login.sh;
	#echo 'echo -n "Login time " >> /home/amelnikov99/Documents/logscript3.txt;' >> /etc/profile.d/script3login.sh;
	#echo 'date +"%d.%m.%Y %R" >> /home/amelnikov99/Documents/logscript3.txt;' >> /etc/profile.d/script3login.sh;
}

do_logout()
{
	#lightdm???
	#touch /home/amelnikov99/Documents/logscript3logout.sh;
	#chmod +x home/amelnikov99/Documents/logscript3logout.sh;
	#echo 'echo -n "Logout time " >> /home/amelnikov99/Documents/logscript3.txt;' >> /home/amelnikov99/Documents/logscript3logout.sh;
	#echo 'date +"%d.%m.%Y %R" >> /home/amelnikov99/Documents/logscript3.txt;' >> /home/amelnikov99/Documents/logscript3logout.sh;
	#echo 'echo -n "Uptime $" u>> /home/amelnikov99/Documents/logscript3.txt;' >> /home/amelnikov99/Documents/logscript3logout.sh;
	#echo 'date +"%d.%m.%Y %R" >> /home/amelnikov99/Documents/logscript3.txt;' >> /home/amelnikov99/Documents/logscript3logout.sh;
	#echo 'session-cleanup-scrtipt=/home/amelnikov99/Documents/logscript3logout.txt' >> /etc/lightdm/lightdm.conf;
	#sudo service lightdm restart;
}




do_start()
{
	echo -n "PC name $HOSTNAME" >> /home/amelnikov99/Documents/logscript3.txt;
	echo -n "Username $USER" >> /home/amelnikov99/Documents/logscript3.txt;
	#for login
	do_login
	#for logout
	do_logout
}

do_stop()
{
	echo -n "Shutdown time " >> /home/amelnikov99/Documents/logscript3.txt;
	date +"%d.%m.%Y %R" >> /home/amelnikov99/Documents/logscript3.txt;
	#Time at the moment after reboot,logout or shutdown
	echo -n "Uptime $" u>> /home/amelnikov99/Documents/logscript3.txt;
	date +"%d.%m.%Y %R" >> /home/amelnikov99/Documents/logscript3.txt;
}

do_reload()
{
	echo -n "Reboot time " >> /home/amelnikov99/Documents/logscript3.txt;
	date +"%d.%m.%Y %R" >> /home/amelnikov99/Documents/logscript3.txt;
	#Time at the moment after reboot,logout or shutdown
	echo -n "Uptime $" u>> /home/amelnikov99/Documents/logscript3.txt;
	date +"%d.%m.%Y %R" >> /home/amelnikov99/Documents/logscript3.txt;
}


case $1 in
  start)
	log_daemon_msg "Starting $DESC"

	start-stop-daemon --start --background $SSD_OPTIONS
	do_start
	#login?
	#logout?
  ;;
  stop)
	log_daemon_msg "Stopping $DESC"
		
	start-stop-daemon --stop $SSD_OPTIONS
	do_stop
  ;;
  restart|force-reload)
	do_reload
	$0 stop
	sleep 1
	$0 start
  ;;
  status)
	status_of_proc "$DAEMON" "$DESC" && exit 0 || exit $?
  ;;
  *)
	N=/etc/init.d/bscript3
	echo "Usage: $N {start|stop|restart|force-reload|status}" >&2
	exit 1
	;;
esac

exit 0
