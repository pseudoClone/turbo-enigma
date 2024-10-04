#!/bin/sh

user=$1

export link=$(curl https://proxitok-instance-put-here.com/@$user | grep "warning" | cut -d'=' -f3 | cut -d'"' -f2)

function iterate(){


	tee downRep/file1.txt <<<"$link"


	for i in $(cat downRep/file1.txt)
	do
		yt-dlp -o "~/pur/nitro/%(title)s.%(ext)s" -fb "$i"
	done
	rm -rf ~/pur/nitro/file1.txt

	curl https://proxitok-instance-put-here.com/@$user | grep "cursor"
	if [ $? -eq 0 ]; then

		cursor_id=$(curl https://proxitok-instance-put-here.com/@$user | grep "cursor" | cut -d'?' -f2 | cut -d'=' -f2 | cut -d'"' -f1)
		export link=$(curl https://proxitok-instance-put-here.com/@$user?cursor=$cursor_id | grep "warning" | cut -d'=' -f3 | cut -d'"' -f2)
		iterate
	fi
	exit
}
iterate

# TODO: function cut()

