#!/bin/sh

user=$1

export link=$(curl https://proxitok.pufe.org/@$user | grep "warning" | cut -d'=' -f3 | cut -d'"' -f2)

function iterate(){


	tee ~/pur/nitro/file1.txt <<<"$link"


	for i in $(cat ~/pur/nitro/file1.txt)
	do
		yt-dlp -o "~/pur/nitro/%(title)s.%(ext)s" -fb "$i"
	done
	rm -rf ~/pur/nitro/file1.txt

	curl https://proxitok.pufe.org/@$user | grep "cursor"
	if [ $? -eq 0 ]; then

		cursor_id=$(curl https://proxitok.pufe.org/@$user | grep "cursor" | cut -d'?' -f2 | cut -d'=' -f2 | cut -d'"' -f1)
		export link=$(curl https://proxitok.pufe.org/@$user?cursor=$cursor_id | grep "warning" | cut -d'=' -f3 | cut -d'"' -f2)
		iterate
	fi
	exit
}
iterate
