# Recitation 4 #

## 'Git' er Done ##

### What's git? ###

Git is a distributed revision control and source code management system with an emphasis on speed.
    
### Make a Data Structures Directory ###

If you haven't already, please make a 3136 directory on your clic account with the following command in your home directory:

    mkdir 3136
    
Change into the directory with the command:

    cd 3136

### Configuring git ###

So in order to use git, you must first let it know who you are.  Do this by telling git your name and email:

    git config --global user.name "Jae Woo Lee" 
    git config --global user.email jae@cs.columbia.edu

Now, put the directory under git revision control with the command:

    git init

### Repositories and Retrieving Assignments ###

A git repository is a place to store fun stuff like code, projects, and in our case recitation notes, homework skeleton code, or homework solutions for you!  Github.com is a website where users make repositories to share and update code with one another.

Once Jae has added the skeleton code for your assignment, you will be able to clone his skeleton code from his repository with the command:

    git clone /home/jae/cs3157-pub/lab1 lab1
    
Once the labs have all been submitted, Jae will post the solutions to his repository.  You can retrieve them with the command:

    git pull

from with in the lab1 subdirectory.

### The 4 levels of Commitment ###

A file in a 

