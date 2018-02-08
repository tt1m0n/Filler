# Filler

 You’ll have to submit a file called author containing your username followed by a ’\n’ at the root of your repository.
 
• The executable file must be named <login>.filler.

• It must be at the root of the repository.

• You must submit a Makefile.

• Your Makefile must compile the project and must contain the usual rules. It must recompile and re-link the program only if necessary.

• If you are clever, you will use your library for your player. Submit also your folder libft including its own Makefile at the root of your repository. Your Makefile will have to compile the library, and then compile your project.

• Your project must be written in accordance with the Norm.

• You have to handle errors carefully. In no way can your program quit in an unex-
pected manner (Segmentation fault, bus error, double free, etc).

• Within your mandatory part, you are allowed to use the following functions:

◦ read

◦ write

◦ malloc

◦ free

◦ perror

◦ strerror

• Good luck and GOOD FIGHT to all!

----------------------------------------------------------------

• In this game, two players fight each other. They play one after the other.

• The goal is to collect as many points as possible by placing the highest number of
pieces on the the game board.

• The board is defined by X columns and N lines, it will then become X*N cells.

• At the beginning of each turn, you will receive your game piece.

• A game piece is defined by X columns and N lines, so it will be X*N cells. Inside each game piece, will be included a shape of one or many cells.

• To be able to place a piece on the board, it is mandatory that one, and only one cell of the shape (in your piece) covers the cell of a shape placed previously (your territory).

• The shape must not exceed the dimensions of the board

• When the game starts, the board already contains one shape.

• The game stops at the first error: either when a game piece cannot be placed anymore or it has been wrongly placed.

-------------------------------------------------------------------

How it is work?

1. Compile project (print make at the root). It will compile all files and create my player omakovsk.filler
2. Go to the resources directory and type something like this [./filler_vm -f maps00 -p1 ../omakovsk.filler -p2 players/abanlin.filler] or you can just type ./filler_vm and program will show you the Usage

