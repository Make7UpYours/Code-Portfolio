##CS 101
##Program 8
##William Freeman
##wjfkc2@mail.umkc.edu
##
##PROBLEM:
##    Create a card came called Accordion using OOP and the Card class that was
##    created.
##
##ALGORITHM:
##    1. Build up a deck of cards and store into a list of cards. Shuffle deck.
##    2. Output menu to user and ask user for input selection from menu choices.
##       a. if user does not make proper selection reprompt menu and selection
##          input.
##    3. If user decides to play a card 1 position back.
##       a. Check to see if the card 1 index space back form user selection is
##          valid.
##          i. If cards are the same suit or rank then discard the card 1 back
##             from user slection
##          ii. If cards are not of same suit or rank then let user know that
##              it is not a legal move and reprompt for input.
##    4. If user selects to play card 3 positions back.
##       a. Check to see if the card 3 index spaces back form user selection
##          is valid.
##          i. If cards are the same suit or rank then discard the card 3 back
##             from user slection.
##          ii. If cards are not of same suit or rank then let user know that
##              it is not a legal move and reprompt for input.
##    5. If user selects to have a list of legal moves shown.
##       a. Iterate through the cards that are in play and if there are cards
##          that have the same rank or suit either 1 space or 3 spaces from
##          another then add that pair to a list along with the space
##          seperation.
##       b. Output list of legal moves to user.
##    6. If user selects to have a count of undealt cards.
##       a. Iterate through the deck list and if the card is face down add 1 to
##          count of cards that are are left to be dealt.
##    7. If user selects to deal next card.
##       a. Iterate through the deck list and turn the first card that is face
##          down face up.
##    8. If user decides to print the help screen.
##       a. Output menu to user from step 3.
##    9. If user decides to resign current game.
##       a. Build new deck and start new game.
##    10. If user decides to exit program.
##        a. Break the loop thus quitting program.
##NOTE: Capitalization of user input should be irrelevant!
##
##ERROR HANDLING:
##    If user makes invalid menu selections then reprompt menu. Ask for input
##    again until a valid selection is made. Capitalization and whitespace
##    before or after input should be irrelevant. If user attempts to make
##    an invalid game move then let them know and continue to ask for input.
##
##OTHER COMMENTS:
#################################
import Card
import random

############################# FUNCTIONS #############################
def build_deck():
    "Build the deck of cards and return the dack as a list."""
    deck_list = []
    for rank in "23456789TJQKA":
        for suit in "HCSD":
            card = Card.Card(rank,suit)
            deck_list.append(card)
    return deck_list

def menu():
    """Prints the menu."""
    print("""Command options:
    1 C - Play card C onto pile 1 position back.
    3 C - Play card C onto pile 3 positions back.
    L - List all legal moves.
    C - Count of undealt cards.
    D - Deal next card.
    H - Print this help screen.
    R - Resign this game (quit early & start a new game).
    X - Exit program.""")

def print_cards(deck_list):
    """Prints cards that are face up in the deck."""
    # iterate through card list and print cards that are face up
    for card in deck_list:
        if card.face_up:
            print(card, end=" ")

def new_game(deck_list):
    """Starts a new game. Builds a new deck for play. Shuffles deck.
       Returns the fresh deck."""
    deck_list = build_deck()
    random.shuffle(deck_list)
    return deck_list

def count_undealt(deck_list):
    """Iterates through the deck list counting the number of cards that are
       undealt. Returns count of undealt cards."""
    count = 0
    for card in deck_list:
        # undealt cards will be face down
        if not card.face_up:
            count += 1
    return count

def deal_card(deck_list):
    """Turns the next card within the deck_list that is face down face up."""
    for card in deck_list:
        # turn first card that is face down up
        # break the loop (do not want to turn all cards face up)
        if not card.face_up:
            card.turn_face_up()
            break
    if deck_list[-1].face_up:
        # all cards are face up
        print("\n----No more cards left in deck----\n")

def play_n_back(n, deck_list, menu_sel_str):
    """Lets the user play a card onto a pile n positions back. Iterates through
       the deck_list and determines if the user's card selection is in the
       deck_list and face up. Function will then determine if the user made a
       valid move selection. Removes card n position back from deck_list."""
    card_str = menu_sel_str[2:].upper()
    found_card_bool = False
    for index, card in enumerate(deck_list):
        # find the card that is face up and matches the user's slection
        if card.rank + card.suit == card_str and card.face_up:
            found_card_bool = True
            # prevent user from accidentally trying to play a card that is not
            # in play
            if index >= n and deck_list[index] == deck_list[index - n]:
                # swap the index of the two cards
                deck_list[index], deck_list[index - n] = \
                                  deck_list[index - n], deck_list[index]
                discard_card = deck_list.pop(index)
                break
            else:
                print("Not a valid move.")
                break
    if found_card_bool == False:
        # if loop completes then card not found matching user's selection
        print("Card not found in play.")

def list_moves(deck_list):
    """Iterates through deck_list and checks for all valid moves. If there are
       no moves found then function lets user know. Otherwise function will
       print a list of valid moves to be had."""
    valid_move_list = []
    # iterate through deck_list and check for valid moves
    for index, card in enumerate(deck_list):
        if card.face_up:
            if index >= 1 and card == deck_list[index - 1]:
                valid_move_list.append("1 " + card.rank + card.suit)
            elif index >= 3 and card == deck_list[index - 3]:
                valid_move_list.append("3 " + card.rank + card.suit)
    if valid_move_list == []:  # no moves found
        print("\n----No moves to be had!----\n")
    else:
        print("\n----Valid moves remaining----")
        for move in valid_move_list:
            print(move)
        print("") # clean up output

############################# MAIN PROGRAM #############################
print("----Welcome to Accordion!----\n")
# initalize variables
deck_list = build_deck()
menu_sel_str = ""
# shuffle deck
random.shuffle(deck_list)

# main game loop, exit if user decides to quit
while menu_sel_str != "x":
    menu()
    # turn first card in shuffled deck face up
    deck_list[0].turn_face_up()
    # start game
    game_on_bool = True
    while game_on_bool == True:
        print_cards(deck_list)
        menu_sel_str = input("\nEnter selection: ")
        menu_sel_str = menu_sel_str.strip().lower()
        if menu_sel_str[0:2] == "1 ":
            play_n_back(1, deck_list, menu_sel_str)
        elif menu_sel_str[0:2] == "3 ":
            play_n_back(3, deck_list, menu_sel_str)
        elif menu_sel_str == "d":
            deal_card(deck_list)            
        elif menu_sel_str == "l":
            list_moves(deck_list)
        elif menu_sel_str == "c":
            count_str = str(count_int)
            print("\n----" + count_str + " cards are left undealt----\n")
        elif menu_sel_str == "h":
            menu()
        elif menu_sel_str == "r":
            print("\n----Starting new game----\n")
            deck_list = new_game(deck_list)
            game_on_bool = False
        elif menu_sel_str == "x":
            print("\n----THANKS FOR PLAYING!----\n")
            game_on_bool = False
        else:
            # user's selection not valid
            menu()

        # keep track of undealt cards
        count_int = count_undealt(deck_list)
        if count_int == 0 and len(deck_list) == 1:
            # all cards dealt and in 1 pile
            # user wins!
            print("\n----YOU WIN!---\n")
            # continue to ask user if they want to play again until they
            # input a proper response
            while True:
                play_again_str = input("Would you like to go again[Y/N]: ")
                play_again_str = play_again_str.strip().lower()
                if play_again_str == "n" or play_again_str == "no":
                    # quit program
                    game_on_bool = False
                    menu_sel_str = "x"
                    break
                elif play_again_str == "y" or play_again_str == "yes":
                    print("\n----Starting new game----\n")
                    deck_list = new_game(deck_list)
                    game_on_bool = False
                    break
                else:
                    print("\n----INVALID RESPONSE!----\n")
    
