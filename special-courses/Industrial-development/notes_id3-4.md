### agnoster

[this is guide to nicer theme instalation](https://medium.com/@genealabs/agnoster-theme-on-os-x-391d60effaf6)

It is possible that it is nessesery to state `antigen theme https://github.com/agnoster/agnoster-zsh-theme agnoster
` too in `.zshrc`. Did not work without that in my case.

### some tmux goodies:

[cheat list for tmux](https://gist.github.com/MohamedAlaa/2961058)

Some picks:

~~~
PREFIX : resize-pane -D (Resizes the current pane down)
PREFIX : resize-pane -U (Resizes the current pane upward)
PREFIX : resize-pane -L (Resizes the current pane left)
PREFIX : resize-pane -R (Resizes the current pane right)
PREFIX : resize-pane -D 20 (Resizes the current pane down by 20 cells)
PREFIX : resize-pane -U 20 (Resizes the current pane upward by 20 cells)
PREFIX : resize-pane -L 20 (Resizes the current pane left by 20 cells)
PREFIX : resize-pane -R 20 (Resizes the current pane right by 20 cells)
PREFIX : resize-pane -t 2 20 (Resizes the pane with the id of 2 down by 20 cells)
PREFIX : resize-pane -t -L 20 (Resizes the pane with the id of 2 left by 20 cells)
~~~

