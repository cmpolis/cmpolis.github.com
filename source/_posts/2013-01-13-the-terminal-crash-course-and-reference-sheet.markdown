---
layout: post
title: "Terminal Crash Course and Reference Sheet"
date: 2013-01-13 14:30
comments: true
categories: 
---
I have been using linux for five or six years and I'm wrapping up my last year of college. I noticed that a lot of first year students and people starting to use linux have trouble getting around the terminal. Most of the time I'm only using a handful of commands and operations. I thought it might be helpful to share some basic usage of these commands and other tricks, so I wrote a short guide and reference sheet that I wish someone had given me when I started using linux: *I'm using Ubuntu and Bash 4.2.8, YMMV*

Basics
-----------------

### Directories:
`.` Current directory

`..` Parent directory

`-` Directory that you were at last
*ex:*

    $ cd ~/Downloads
    $ cd ~/Documents
    $ cd -
    [now you are back in Downloads]
    
`~` Home directory, contains personal files, *equivalent to `/home/[your username]/`*

`/` Root directory, the parent directory for all files

### Commands

#### Navigation

`cd` Choose Directory - move to a given directory <br />
*ex:* `$ cd ~/Desktop`

`ls` List files in the current directory <br />
*Options: <br />
`-a` list all files (some files are hidden otherwise) <br />
`-l` list files with metadata like permissions, timestamp and size*

`pwd` Prints the absolute path of the directory thta you are in

`mkdir [new dir name]` Creates a new directory with a relative or absolute path<br />
*ex:*
    $ mkdir newDirA # creates a directory as a child of the current directory
    $ mkdir ~/Desktop/newDirB # creates a new directory on the desktop

#### System Management
`ps` Lists processes, `ps aux` prints all processes that the current user can see and should be used in most cases

`top` Shows system(CPU, mem, processes) status dynamically. Hit `q` key to exit.

`kill` Sends a signal to a process, usually to terminate it. Takes in a pid(can be obtained from `ps`) as an argument.


`free` Lists memory usage stats `-m` displays numbers in Mb and can be easier to read

`df` Lists hard disk usage stats (also takes `-m` option)


#### Files
`cat` Print out a file in the terminal

`rm` Removes a file<br />
*Options: <br />
`-r` Recursivly remove files (use for directories)<br />
`-f` Force removing files, ie the user isn't prompted and a warning isnt given if the file does not exist<br />
BE CAREFUL WITH RM, especially -with `-r` and `-f`!*

`mv [file] [destination]` Moves a file

`cp [file] [destination]` Copies a file

`ln` Make a link(alias) to a file - you can open/read/edit the file using the link <br />
*ex:* `$ ln ~/Downloads/someFile` creates a link to this file in the current directory.

`chmod [permission] [file]` Change file permissions/mode. [More info](http://en.wikipedia.org/wiki/Chmod)<br />
*There are many different possible permissions, here are some useful ones:*<br />
    chmod 777 [file] # All users can read/write/execute
    chmod 755 [file] # All can read and execute, only owner can write
    chmod a+x [file] # Make a file executable

`tail` Prints the last 10 or `-#` # of lines of a file

`head` Prints the first 10 or `-#` # of lines of a file

`diff` Show differences between two files <br />
*ex:*

    $ cat a
    foo bar
    $ cat b
    foo
    $ diff a b
    1c1
    < foo bar
    ---
    > foo

`emacs/vim/nano` Text editors. I personally like VIM, but everyone has their preference and VIM has a decent learning curve.

#### Misc
`man [command name]` **IMPORTANT** Shows the manual page for a given command 

`grep [pattern] [filename]` Searches a file for a regex or text pattern 

`time [command]` Runs a command and displays the time it takes to execute

`history` Prints previously run commands

`wget [URL]` Downloads the file at the given URL


Complicating Things...
------------------

#### Shortcuts
`up/down arrow keys` Toggle through previously run terminal commands

`ctrl+c` Attempts to shutdown the process that is running in the terminal (sends a SIGINT)

`ctrl+z` Kills the process that is running in the terminal, similar to `ctrl+c`, but more intrusive and will always work(sends a SIGSTOP)

`tab` Autocompletes a file or command name in the terminal. Will only fully autocomplete if there is one option or will complete partially if all possibilities share part of their name. <br />
*ex: `$ cd ~/Down [hit tab]` -> `$ cd/Downloads`* 

`hit tab twice` Shows options to finish command or filename<br />
*ex:*

    $ cd  ~/D [hit tab twice]
    Desktop/   Documents/ Downloads/ Dropbox/ 
    $ cd ~/D 

#### Combining terminal commands 
`[command one] && [command two]` Pipe: Run command one, then run command two<br />
*ex: `mkdir newDir && cd newDir` to make a directory and navigate into it*

`[command one] | [command two]` Use the output from command one as input for command two<br />
*ex: `history | grep git` to search history for when git commands were run*

#### Redirection
`[command] > [file]` Redirect out: Instead of printing to the terminal, put the output in a file 

`[command] < [file]` Redirect in: Get input from a file instead of the terminal

#### Bang!
`!!` Run the last command that was executed

`!#` Runs the command with a given line # that can be found from `history`<br />
*ex:*

    $ history | grep git
    1735  git status
    1736  git add .
    $ !1735  # Runs 'git status'

`![pattern]` Run the last command you executed that started with 'pattern'

*I hope this helps!*
