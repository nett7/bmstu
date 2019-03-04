# Industrial development 4

`curl cheat.sh/<com>` - cheat man

~~~
➜ curl cheat.sh/cmake
#
# cmake
#
# Cross-platform build system generator.
# It generates Makefiles, Visual Studio projects or others, depending on the target system.
#
# Generate a Makefile and use it to compile a project in the same directory as the source:
  cmake && make
#
# Generate a Makefile and use it to compile a project in a separate "build" directory (out-of-source build):                                                                                                
  cmake -H. -Bbuild && make -C build
#
# Run cmake in interactive mode (it will ask for each variable, instead of using defaults):
  cmake -i
#
#

~~~

`tmux> C-b + [` - copy mode (to scroll stuff)

`cheat` - python note thingy

`cheat -e <note-name>` - make notes locally

`cheat <note-name>` - to open note

`cheat-ext` - clone cheat lists from remote repos

## tmux
- Terminal multiplexer.

~~~
set -g @plugin 'tmux-plugins/tmux-sensible'
set -g @plugin 'tmux-plugins/tmux-yank'
set -g @plugin 'tmux-plugins/tmux-copycat'            # simple copy to clipboard
set -g @plugin 'nhdaly/tmux-better-mouse-mode'
set -g @plugin 'tmux-plugins/tmux-resurrect'          # restore -
set -g @plugin 'tmux-plugins/tmux-continuum'          #  - sessons
set -g @plugin 'jbnicolai/tmux-fpp'
set -g @plugin 'Morantron/tmux-fingers'
set -g @plugin 'tmux-plugins/tmux-open'
set -g @plugin 'tmux-plugins/tmux-sidebar'
set -g @sidebar-tree-command 'tree -C'
~~~

## File Manager

`vifm`


## git extras

[command list](https://github.com/tj/git-extras/blob/master/Commands.md#git-reauthor)

`git setup` - quick init and commit

`git summary` - 

~~~
➜ git summary                                                                                      
Alias tip: g summary
project  : timp
repo age : 11 months
active   : 6 days
commits  : 33
files    : 25
authors  :
    25  yokkidack    75.8%
    8  Roshin Igor  24.2%
~~~

NOTE:

~~~
git summary does not show co-authors if they were added as co-authors in commit massage, even tho they│
 appear as co-authors in github/insights/contributers;                                                │
                                                                                                      │
git summary shows authors as different, even tho they have identical names and e-mails; Author #1 comm│
ited to repo in gitlab, Author #2 cloned repo into github and commited into it, Author #3 pulled repo,│
 commeded into it and then pushed it into github; 
~~~
