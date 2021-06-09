# Projekt - Szachy

Implementacja gry w szachy w interfejsie konsolowym. Umożliwia grę z drugim graczem i botem.


## Objaśnienia gry

Szachownica wyświetla się w konsoli. Gracz wybiera ruchy poprzez wprowadzanie numerów odpowiednich opcji. Białe figury znajdują się na górze i oznaczone są małymi literami. Czarne - na dole, duże litery.

## Podział odpowiedzialności

- Stanisław Zagórowski - klasa Piece i dziedziczące po niej klasy każdej z figur, klasa Position.
- Bartłomiej Dudek - klasa Player i dziedziczące po niej klasy gracza i bota.
- Konrad Wojda - klasa Chessboard odpowiedzialna za szachownicę, klasa Game - interfejs.

## Diagram dziedziczenia
```mermaid
graph TD;
 Piece-->Pawn; 
Piece-->Knight;
Piece-->Bishop;
 Piece-->Rook;
 Piece-->Queen;
 Piece-->King;
 ```
 ```mermaid
graph TD;
 Player-->Human; 
Player-->RandIntBot;
 ```
  ```mermaid
graph TD;
 Chessboard; 
 ```
   ```mermaid
graph TD;
 Game; 
 ```
