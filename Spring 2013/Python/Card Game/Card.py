##CS 101
##Program 8 - Card class
##William Freeman
##wjfkc2@mail.umkc.edu
##
##PROBLEM:
##    Create a Card class which will be used in OOP for program 8.
##
##ALGORITHM:
##    class Card:
##    methods:
##    __init__(rank, suit)
##        1. set Card.rank = rank
##        2. set Card.suit = suit
##        3. initialize Card.face_up = False
##
##    turn_face_up()
##        1. set Card.face_up = True
##
##    turn_face_down()
##        1. set Card.face_up = False
##
##    __repr__()
##        1. return Card.rank + Card.suit
##
##    __str__()
##        1. if Card is not face_up
##            a. return "XX"
##        2. if Card is face_up
##            a. return Card.rank + Card.suit
##
##    __eq__(other_Card)
##        1. if the two Cards are of same suit or rank
##            a. return True
##        2. if the two Cards are not of same suit or rank
##            a. return False
##
##ERROR HANDLING:
##
##OTHER COMMENTS:
#################################
class Card(object):
    def __init__(self, rank="", suit=""):
        """Initializes member variables for the Card class. Cards are always
           face down when initalized."""
        self.suit = suit
        self.rank = rank
        self.face_up = False

    def turn_face_up(self):
        """Sets the member variable face_up to True."""
        self.face_up = True

    def turn_face_down(self):
        """Sets the member variable face_up to False."""
        self.face_up = False

    def __str__(self):
        """print representation. If Card is face down print "XX", if face
           up print a string concatenation of the Card's rank and suit."""
        if not self.face_up:
            return "XX"
        else:
            return self.rank + self.suit

    def __repr__(self):
        """Represent each Card as a concatenation of its rank and suit."""
        return self.rank + self.suit
        
    def __eq__(self, other_card):
        """Cards are == when one Card has the same rank or suit of another
           Card instance."""
        if self.rank == other_card.rank or self.suit == other_card.suit:
            return True
        else:
            return False
