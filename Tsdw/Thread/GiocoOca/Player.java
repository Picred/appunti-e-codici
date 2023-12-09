package GiocoOca;

public class Player extends Thread {
    int pos = 0; // Posizione del giocatore
    int index;
    Game game;

    Player(int index, Game g) {
        this.index = index;
        game = g;
    }

    @Override
    public void run(){
        while(true){
            int turno = game.getRound();
            System.out.println("TURNO va a " + turno);

            if(turno == index){ // è il mio turno
                System.out.println("Giocatore " + index + " sta giocando");
                pos += tiraDadi();
                if (pos >= 100){
                    System.out.println("Ha vinto " + index);
                    game.setRound(-1);
                    game.gameNotify();
                    break;
                } else{
                    game.setRound(1-index);
                    game.gameNotify();
                    try {
                        game.gameSleep();
                    } catch (InterruptedException e){
                        e.printStackTrace();
                    }
                    
                }
            } else if (turno == -1){ // Non è il mio turno ma la partita è finita
                System.out.println("Ho perso!");
                break;
            } else {
                try {
                    game.gameWait();
                } catch (InterruptedException e){
                    e.printStackTrace();
                }
            }
        }
    }

    int tiraDadi(){
        int result = (int)(Math.random() * 10 + 2);
        System.out.println("Dado: " + result);

        return result;
    }

}
