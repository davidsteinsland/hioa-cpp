#ifndef CLASS_CARD
#define CLASS_CARD

#include <vector>
#include <string>

//Anything card-related goes here
namespace cards{

  //Shorthand enum for suits
  typedef enum{SPADES,HEARTS,CLUBS,DIAMONDS} t_suit; 

  //Rank is OK as char
  typedef char t_rank;

  //Tracking array sizes (Defined ONLY here)
  const int NUM_SUITS=4;
  const int NUM_RANKS=13;

  //Suit-names, for printing
  const std::string suit_name[]={"SPADES","HEARTS","CLUBS","DIAMONDS"};
  
  //Ranks - both as data and for printing
  const t_rank ranks[NUM_RANKS]=
    {'2','3','4','5','6','7','8','9','T','J','Q','K','A'};
    
  /// A single card 
  class card{
    t_suit suit;
    t_rank rank;
  public:
    card(t_suit,t_rank);
    std::string name();
    t_suit getSuit();
    t_rank getRank();
  };
  
      
} //End of namespace

#endif
