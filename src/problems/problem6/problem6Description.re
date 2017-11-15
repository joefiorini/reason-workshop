let src = {|
# Problem 6 - Modularity all in one Place!

## Requirements
* Define a module Square inside the file problem6.re
* Render two squares next to each other of different sizes

## Instructions

The other way to define a module is inside a file. You can nest as many modules as you like, which operates as a kind of namespacing. Each module is contextually aware of its contents, and of the "file" modules, but not of their innards. This presents a tidy way to encapsulate functionality related to some singular concern.

For instance, we might see a module defined and consumed like so:

```reason
/* inside poker.re */

module Card = {
  type suit = Spades | Hearts | Clubs | Diamonds;
  type face = One | Two | Three;
  type card = Card(suit, face);

  let show = (card) => {
    switch card {
    | Card(Spades, One) => "One of Spades"
    | Card(Spades, Two) => "Two of Spades"
    | Card(Spades, Three) => "Three of Spades"
    | Card(Hearts, One) => "One of Hearts"
    | Card(Hearts, Two) => "Two of Hearts"
    | Card(Hearts, Three) => "Three of Hearts"
    | _ => "impl"
    }
  };
};

module Deck = {
  open Card;
  type t = list(card);

  let make: t = [
    Card(Spades, One),
    Card(Spades, Two),
    Card(Spades, Three),
    Card(Hearts, One),
    Card(Hearts, Two),
    Card(Hearts, Three)
  ];

  let draw = (deck: t) : (card, list(card)) => {
    (List.hd(deck), List.tl(deck))
  };

  let show = (deck) => {
    List.fold_right((a, b) => Card.show(a) ++ " " ++ b, deck, "")
  };
};

module Hand = {
  open Card;
  type t = list(card);

  let maxSize = 5;

  let show = (hand) => {
    List.fold_right((a, b) => Card.show(a) ++ " " ++ b, hand, "")
  };

  let rec make' = (deck: Deck.t, hand: t) => {
    if (List.length(hand) >= maxSize) {
      (deck, hand)
    } else {
      let (card', deck') = Deck.draw(deck);
      make'(deck', [card', ...hand])
    }
  };

  let make = (deck) => make'(deck, []);
};

/* in game.re */
open Poker;

let deck = Deck.make;
let (_, hand) = Hand.make(deck);
Js.log @@ Hand.show(hand);
```

By defining the modules inside one file, they can share types easily and co-locate and shared expressions.

Using your solution to the last problem, create a module inside problem6.re that contains all the lines from your files `problem5Square.re` and `problem5Square.rei`.
|};
