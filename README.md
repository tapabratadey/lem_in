# Lem-in

![DEMO](https://user-images.githubusercontent.com/12387917/43361458-dddb759e-9283-11e8-8779-d5bb626b31d2.gif)

Lem-in, an implementation of the pathfinding algorithm in C. This algorithm analyses a unique input with a variable number of ants and then helps the colony navigate from the start of a maze to the end. There are some basic constraints, to be the first to arrive, ants will need to take the shortest path. They will also need to avoid traffic jams as well as walking all over their fellow ants. The program reads in a map through standard in, which has information about the number of ants, rooms, room coordinates, and which rooms link to which. All these data are stored in an ant, a room, and a link struct. Since I know the starting room and the ending room, I traverse from the starting room to all the rooms and store every child room (which becomes parent rooms later) in an array until I reach the end room. Once I reach the end, I find each rooms’ parents, until I get to the starting room and reverse the order of the path, and then send one ant at a time to the connecting rooms, keeping in mind that ants can only move one at a time to a room, I keep track of the ants using flags. I start displaying the ants by its number to the room it moves to until all the ants reach the end room.</br>

Steps to run Lem-in:</br>
Copy and paste the following line in your terminal</br>

git clone https://github.com/tapabratadey/lem_in.git && cd lem_in_2.0 && sh run.sh

To run the program:</br>
./lem-in < maps/"pass-in-any-file-you-want-to-test-with"</br>
