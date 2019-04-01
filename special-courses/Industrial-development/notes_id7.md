`git ignore-io`

Generate sample gitignore file from [gitignore.io](https://www.gitignore.io)

Without option, `git ignore-io <type>` shows the sample gitignore of specified types on screen.

```bash
$ git ignore-io vim

    # Created by https://www.gitignore.io/api/vim

    ### Vim ###
    [._]*.s[a-w][a-z]
    [._]s[a-w][a-z]
    *.un~
    Session.vim
    .netrwhist
    *~
```

To export it to `.gitignore` file you can use the following options:

* `-a` or `--append` to append the result to `.gitignore`
* `-r` or `--replace` to export `.gitignore` with the result

```bash
$ git ignore-io vim python
```

For efficiency, `git ignore-io` store all available types at `~/.gi_list`.
To list all the available types:

* `-l` or `-L` : These two options will show the list in different format. Just try it.

You can also search type from the list by:

* `-s <word>` or `--search <word>`

```bash
$ git ignore-io -s ja

    django
    jabref
    java
    ninja
```

