/*
    Author: Evan A Goddard
    Date: 11/28/25 - 12/15/25
    Purpose: Final Project

    Citations: 
        https://www.geeksforgeeks.org/cpp/function-prototypes-in-cpp/
            Purpose: Prototype information to stop compiler complaints and errors
*/

/*
Listing of cases:
blackjack
hit
stand
double down
insurance
*/


#define BLACKJACKPAY 1.5
#include <iostream>
#include <fstream>
#include "queue.hpp"
#include "deck.hpp"
#include "card.hpp"
#include "hand.hpp"
#include <vector>
using namespace std;


void menu() {
    cout << "Would you like to play a round of blackjack?\n";
    cout << "Enter a 1 if you would like to play a round of blackjack\n";
    cout << "Enter the integer 2 if you would like to exit the program, and not play a round of blackjack\n";
}


void reg_round(Deck &d, double bet, double &chips, Queue &c);
void split_round(Deck &d, double bet, double &chips, Hand &p, Hand &dealer, Queue &c);
void round(Deck &d, double bet, double &chips, Hand &p, Hand &dealer, Queue &c);

void reg_round(Deck &d, double bet, double &chips, Queue &c) {
    Hand dealer = Hand();
    Hand player = Hand();
    player.push_back(d.deal());
    dealer.push_back(d.deal());
    player.push_back(d.deal()); //deal out the cards to both players
    dealer.push_back(d.deal());
    c.enqueue(player.get_card(0));
    c.enqueue(player.get_card(1));
    c.enqueue(dealer.get_card(0)); // don't add dealers second card to counter because player can't yet see it, so its not in card count
    round(d, bet, chips, player, dealer, c);
}
void split_round(Deck &d, double bet, double &chips, Hand &p, Hand &dealer, Queue &c) {
    double bet1 = bet;
    double bet2 = bet;
    bool end_of_round1 = false;
    bool end_of_round2 = false;
    Hand p1 = Hand();
    Hand p2 = Hand();
    p1.push_back(p.get_card(0));
    p2.push_back(p.get_card(1));
    p1.push_back(d.deal());
    p2.push_back(d.deal());

    c.enqueue(p1.back());
    c.enqueue(p2.back());

    cout << "Hand 1:\n";
    p1.get_card(0).displayCard();
    p1.get_card(1).displayCard();

    cout << "Hand 2:\n";
    p2.get_card(0).displayCard();
    p2.get_card(1).displayCard();


    bool skip1 = false;
    bool skip2 = false;
    if (p1.get_sum() == 21) {
        cout << "Blackjack in hand 1!\n";
        if (dealer.get_sum() == 21) {
            cout << "Blackjack in dealer hand push!\n";
        }
        else {
            chips += bet1;
        }
        end_of_round1 = true;
        skip1 = true;
    }
    if (p2.get_sum() == 21) {
        cout << "Blackjack in hand 2!\n";
        if (dealer.get_sum() == 21) {
            cout << "Blackjack in dealer hand push!\n";
        }
        else {
            chips += bet2;
        }
        end_of_round2 = true;
        skip2 = true;
    }
    bool bust1 = false;
    bool bust2 = false;
    while (!end_of_round1) { // continue the game 
        cout << "You currently have " << p1.get_sum() << endl;
        cout << "Card count is currently: " << c.getCount() << "\n";
        cout << "If you would like to hit enter a 1\n";
        cout << "If you would like to stand enter a 2\n";
        if (bet1 *2 <= chips) {
            cout << "If you would like to double down enter a 3\n";
        }
        int choice_1;
        while (!(cin >> choice_1)) { // get the number and will loop if not a number to handle errors
			cin.clear();           // clears the error
			cin.ignore();          // ignores what was entered
			cout << "Sorry, that was not a valid option.  Try again\n";
            cout << "If you would like to hit enter a 1\n";
            cout << "If you would like to stand enter a 2\n";
            if (bet1 *2 <= chips) {
                cout << "If you would like to double down enter a 3\n";
            }
		}
        if (choice_1 == 3) {
            if (bet1 * 2 <= chips) {
                end_of_round1 = true;
                p1.push_back(d.deal());
                bet1 *=2;

                c.enqueue(p1.back());

                cout << "Card dealt to player:\n";
                p1.back().displayCard();
                
            }
            else {
                cout << "invalid option, you don't have enough chips to double down!\n";
            }
        }
        else if (choice_1 == 1) {
            p1.push_back(d.deal());

            c.enqueue(p1.back());
            cout << "Card dealt to player:\n";
            p1.back().displayCard();
        }
        else if (choice_1 == 2) {
            end_of_round1 = true;
        }
        if (p1.get_sum() > 21) {
            if (p1.get_ace() > 0) {
                p1.decrement_10();
            }
            else {
                cout << "Bust! Player Loses!\n";
                chips -= bet1;
                bust1 = true;
                end_of_round1 = true;
                
            }
        }
    }
    while (!end_of_round2) { // continue the game 
        cout << "You currently have " << p2.get_sum() << endl;
        cout << "Card count is currently: " << c.getCount() << "\n";
        cout << "If you would like to hit enter a 1\n";
        cout << "If you would like to stand enter a 2\n";
        if (bet2 *2 <= chips) {
            cout << "If you would like to double down enter a 3\n";
        }
        int choice_1;
        while (!(cin >> choice_1)) { // get the number and will loop if not a number to handle errors
			cin.clear();           // clears the error
			cin.ignore();          // ignores what was entered
			cout << "Sorry, that was not a valid option.  Try again\n";
            cout << "If you would like to hit enter a 1\n";
            cout << "If you would like to stand enter a 2\n";
            if (bet2 *2 <= chips) {
                cout << "If you would like to double down enter a 3\n";
            }
		}
        if (choice_1 == 3) {
            if (bet2 * 2 <= chips) {
                end_of_round2 = true;
                p2.push_back(d.deal());
                bet2 *=2;
                c.enqueue(p2.back());
                cout << "Card dealt to player:\n";
                p2.back().displayCard();
                
            }
            else {
                cout << "invalid option, you don't have enough chips to double down!\n";
            }
        }
        else if (choice_1 == 1) {
            p2.push_back(d.deal());
            c.enqueue(p2.back());
            cout << "Card dealt to player:\n";
            p2.back().displayCard();
        }
        else if (choice_1 == 2) {
            end_of_round2 = true;
        }
        if (p2.get_sum() > 21) {
            if (p2.get_ace() > 0) {
                p2.decrement_10();
            }
            else {
                cout << "Bust! Player Loses!\n";
                chips -= bet2;
                bust2 = true;
                end_of_round2 = true;                              // need bools bust 1 and bust 2
            }
        }
    }

    cout << "Dealers face down card:\n";
    dealer.get_card(1).displayCard();
    c.enqueue(dealer.back());
    while (dealer.get_sum() < 17) { 
        dealer.push_back(d.deal());
        cout << "Card dealt to dealer:\n";
        dealer.back().displayCard();

        c.enqueue(dealer.back());

        if (dealer.get_sum() > 21 && dealer.get_ace() > 0) {
            dealer.decrement_10();
        }
    }
    cout << "Player total 1: " << p1.get_sum() << endl;
    cout << "Player total 2: " << p2.get_sum() << endl;
    cout << "Dealer total: " << dealer.get_sum() << endl;


    if (dealer.get_sum() > 21) {
        if (!bust1 && !bust2 && !skip1 && !skip2) {
            cout << "Dealer busts, player wins!\n";
            chips = chips + bet1 + bet2;
        }
        else if (!bust2 && !skip2) {
            cout << "Dealer busts, player wins!\n";
            chips += bet2;
        }
        else if (!bust1 && !skip1) {
            cout << "Dealer busts, player wins!\n";
            chips += bet1;
        }
        
    }

    else  {
        if (!skip1 && !bust1) {
            if (dealer.get_sum() > p1.get_sum()) {
                cout << "Dealer wins!\n";
                chips -= bet1;
            }
            else if (dealer.get_sum() < p1.get_sum()) {
                cout << "Player wins!\n";
                chips += bet1;
            }
            else {
                cout << "Push, player and dealer are even!\n";
            }
        }
        if (!skip2 && !bust2) {
            if (dealer.get_sum() > p2.get_sum()) {
                cout << "Dealer wins!\n";
                chips -= bet2;
            }
            else if (dealer.get_sum() < p2.get_sum()) {
                cout << "Player wins!\n";
                chips += bet2;
            }
            else {
                cout << "Push, player and dealer are even!\n";
            }
        }
    }


}
void round(Deck &d, double bet, double &chips, Hand &p, Hand &dealer, Queue &c) {
    bool end_of_round = false; 
    /*
    vector<Card> dealer;
    vector<Card> player;
    player.push_back(d.deal());
    dealer.push_back(d.deal());
    player.push_back(d.deal()); //deal out the cards to both players
    dealer.push_back(d.deal());
    */

    cout << "Your cards:\n"; // display these cards
    p.get_card(0).displayCard();
    p.get_card(1).displayCard();
    cout << "The dealers up card:\n";
    dealer.get_card(0).displayCard();

    if (p.get_sum() == 21) {// handle the case of blackjack
        cout << "Blackjack!\n";
        if (dealer.get_sum() == 21) {
            cout << "Dealer's second card:\n";
            dealer.back().displayCard();
            cout << "Dealer Blackjack as well! Push\n";
        }
        else {
            chips = chips + (bet * BLACKJACKPAY);
        }
        return;
    }

    if (p.get_card(0).getRank() == p.get_card(1).getRank() && bet * 2 <= chips) {
        cout << "Would you like to split?\n";
        cout << "Enter a 1 if you would like to split\n";
        cout << "Enter a 0 if you wouldn't like to split\n";
        int choice_2;
        while (!(cin >> choice_2)) { // get the number and will loop if not a number to handle errors
			cin.clear();           // clears the error
			cin.ignore();          // ignores what was entered
			cout << "Sorry, that was not a valid option.  Try again\n";
            cout << "Enter a 1 if you would like to split\n";
            cout << "Enter a 0 if you wouldn't like to split\n";
		}
        if (choice_2 == 1) {
            split_round(d, bet, chips, p, dealer, c);
            return;
        }
    }

    while (!end_of_round) { // continue the game 
        cout << "You currently have " << p.get_sum() << endl;
        cout << "Card count is currently: " << c.getCount() << "\n";
        cout << "If you would like to hit enter a 1\n";
        cout << "If you would like to stand enter a 2\n";
        if (bet *2 <= chips) {
            cout << "If you would like to double down enter a 3\n";
        }
        int choice_1;
        while (!(cin >> choice_1)) { // get the number and will loop if not a number to handle errors
			cin.clear();           // clears the error
			cin.ignore();          // ignores what was entered
			cout << "Sorry, that was not a valid option.  Try again\n";
            cout << "If you would like to hit enter a 1\n";
            cout << "If you would like to stand enter a 2\n";
            if (bet *2 <= chips) {
                cout << "If you would like to double down enter a 3\n";
            }
		}
        if (choice_1 == 3) {
            if (bet * 2 <= chips) {
                end_of_round = true;
                p.push_back(d.deal());
                bet *=2;
                c.enqueue(p.back());
                cout << "Card dealt to player:\n";
                p.back().displayCard();
                
            }
            else {
                cout << "invalid option, you don't have enough chips to double down!\n";
            }
        }
        else if (choice_1 == 1) {
            p.push_back(d.deal());
            cout << "Card dealt to player:\n";
            p.back().displayCard();
            c.enqueue(p.back());
        }
        else if (choice_1 == 2) {
            end_of_round = true;
        }
        if (p.get_sum() > 21) {
            if (p.get_ace() > 0) {
                p.decrement_10();
            }
            else {
                cout << "Bust! Player Loses!\n";
                chips -= bet;
                return;
            }
        }
    } // end of round

    cout << "Dealers face down card:\n";
    dealer.get_card(1).displayCard();
    c.enqueue(dealer.back());
    while (dealer.get_sum() < 17) { // going to use soft 17 rules for simplicity sake and as well it gives the player a better chance
        dealer.push_back(d.deal());
        cout << "Card dealt to dealer:\n";
        dealer.back().displayCard();
        c.enqueue(dealer.back());

        if (dealer.get_sum() > 21 && dealer.get_ace() > 0) {
            dealer.decrement_10();
        }
    }
    cout << "Player total: " << p.get_sum() << endl;
    cout << "Dealer total: " << dealer.get_sum() << endl;
    if (dealer.get_sum() > 21) {
        cout << "Dealer busts, player wins!\n";
        chips += bet;
        
    }

    else if (dealer.get_sum() > p.get_sum()) {
        cout << "Dealer wins!\n";
        chips -= bet;
    }
    else if (dealer.get_sum() < p.get_sum()) {
        cout << "Player wins!\n";
        chips += bet;
    }
    else {
        cout << "Push, player and dealer are even!\n";
    }

}

int main(int argc, char * argv[]) {
    ifstream if_stream;
    ofstream of_stream;
    if (argc < 2) {
        cerr << "Error, missing command line statement\n";
        exit(1);
    }
    string infile = argv[1];
    if_stream.open(infile);
    if (if_stream.fail()) {
        cerr << "File failed to open correctly\n";
        exit(1);
    }
    double chips;
    if (!(if_stream >> chips)) { // why is this error here?
        cerr << "Error reading file!\n";
        exit(1);
    }
    //handles errors with reading from file is still needed
    if_stream.close();

    Deck d = Deck();
    d.callsort();
    cout << "Here is the unshuffled deck\n";
    d.printDeck();
    d.shuffle();
    cout << "The deck has now been shuffled\n";
    cout << "This program will play blackjack!\n";
    cout << "The houses rules are as follows:\n" << endl;
    cout << "When both the dealer and the player get natural blackjacks, they both get 21 on the initial deal, its a push, no chips are lost or gained by the player\n";
    cout << "A natural blackjack always beats 21 after hitting\n";
    cout << "If the player gets two cards, initially, of the same rank they get the opportunity to split, this creates two different games each with one of these cards\n";
    cout << "However, then Blackjack will be payed out regularly, 1:1 in a split hand, instead of 3:2 how blackjack is paid out regularly\n";
    cout << "The player can hit (ask for another card), stand (choose to stop recieveing cards),\n";
    cout << "or double down (where you get one more card, but you have to stand after that card and your bet doubles)\n";
    cout << "The dealer will hit until they get to a 17, even a soft one, this means including an ace, and then stand\n";
    cout << "And as always the goal is to get as close to 21 without going over, which means a bust and a loss\n\n";

    cout << "In addition the program has implemented a card counting system, so here is a little overview on card counting\n";
    cout << "Card counting is where you keep track of which cards have been dealt in order to give yourself a little bit of a better chance at winning\n";
    cout << "A card 2-6 will cause the count to increase by 1, 10-K and Aces will decrease the score by 1, and a 7-9 card won't affect the card count at all\n";
    cout << "General strategy is that you should expect more higher cards when the card count is high, therefore you should bet more in anticipation of blackjack,\n";
    cout << "And double down more often when you get dealt cards equal to 10 initially, as you will likely get a high score after the next hit\n";    
    cout << "Otherwise have at it, make sure to enter simlpy an integer whenever it asks for a number to do a certain process\n";
    cout << "Example if you want to hit simply enter \"1\"" << endl;
    Queue counter = Queue();

    bool b = true;
    while (b) {
        menu();
        int choice_0;
        while (!(cin >> choice_0)) { // get the number and will loop if not a number to handle errors
			cin.clear();           // clears the error
			cin.ignore();          // ignores what was entered
			cout << "Sorry, that was not a valid option.  Try again\n";
            menu();
		}
        if (choice_0 == 1) {
            double bet = 0;
            bool vbet = false;
            cout << "What would you like to bet?\n";
            cout << "Card count is currently: " << counter.getCount() << "\n";
            while (!vbet) { // get the number and will loop if not a number to handle errors
                if (!(cin >> bet)) {
			        cin.clear();           // clears the error
			        cin.ignore();          // ignores what was entered
			        cout << "Sorry, that was not a valid option.  Try again\n";
                    cout << "What would you like to bet?\n";
                    cout << "Card count is currently: " << counter.getCount() << "\n";
		        }
                else if (bet > chips || bet < 0) {
                    cout << "You bet needs to be less than or equal to you chip amount and greater than 0, try again!\n";
                    cout << "Current chip amount " << chips << endl;
                }
                else {
                    vbet = true;
                }
            }
            reg_round(d,bet,chips, counter);
            cout << "Your current amount of chips is: " << chips << endl;
            if (d.getRemaining() < 21) { // 21 is chosen using the worst case in which the player uses as much cards as they can in a round
                d.shuffle(); // therefore since we shuffle every time they get below 21 cards there is no possibility that we can fail to deal
                cout << "Shuffling, card count is resetting\n";
                counter.reset();
            }
        }
        
        else if (choice_0 == 2) {
            b = false;
        }
    }
    of_stream.open(infile);
    if (of_stream.fail()) {
        cerr << "File failed to open correctly\n";
        exit(1);
    }
    of_stream << chips;
    of_stream.close();
    cout << "Final chips amount is " << chips << endl; 

}