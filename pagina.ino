
void codice() {
String html="<html><head> <title>Traliccio - by Easyino</title> <link rel='stylesheet' href='https://stackpath.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css' integrity='sha384-JcKb8q3iqJ61gNV9KGb8thSsNjpSL0n8PARn9HuZOnIxN0hoP+VmmDGMN5t9UJ0Z' crossorigin='anonymous'> <script src='https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.12.9/umd/popper.min.js' integrity='sha384-ApNbgh9B+Y1QKtv3Rn7W3mgPxhU9K/ScQsAP7hUibX39j7fakFPskvXusvfa0b4Q' crossorigin='anonymous'></script> <script src='https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js'></script> <script src='https://stackpath.bootstrapcdn.com/bootstrap/4.5.2/js/bootstrap.min.js' integrity='sha384-B4gt1jrGC7Jh4AgTPSdUtOBvfO8shuf57BaghqFfPlYxofvL8/KUEfYiJOMMV+rV' crossorigin='anonymous'></script> <script type='text/javascript' src='https://canvasjs.com/assets/script/canvasjs.min.js'></script> <style> .rounded-tondo { border-radius: 1rem !important; padding: 20px; } .rounded-tondo-solo { border-radius: 1rem !important; } .rounded-tondo-bordo { border-radius: 1rem !important; padding-right: 87px; padding-left: 88px; padding-top: 20px; padding-bottom: 20px; } .rounded-tondo-sopra { border-radius: 2rem !important; padding-top: 10px; padding-bottom: 10px; } div.grigio { background-color: #60656f; } .container { position: static; text-align: center; } .rosso { background-color: #E94F37; } .verde { background-color: #33CA7F; } .azzurro { background-color: #7BB2D9; } .giallo { background-color: #DBAD6A; } .grigietto { background-color: #C1C9D7; } </style> <script> function scarica() { var url = './dati'; $.ajax({ url: url, success: function (result) { document.getElementById('tutto').innerHTML = result; setTimeout(scarica, 10) } }); } </script></head><body onload='setTimeout(scarica, 10)'> <div class='modal fade' id='Modal' tabindex='-1' role='dialog' aria-labelledby='exampleModalLabel' aria-hidden='true'> <div class='modal-dialog' role='document'> <div class='modal-content'> <div class='modal-header'> <h5 class='modal-title' id='exampleModalLabel'>Danger!</h5> <button type='button' class='close' data-dismiss='modal' aria-label='Close'> <span aria-hidden='true'>&times;</span> </button> </div> <div class='modal-body'> There are to much houses for this pylon, o na roba del genere </div> <div class='modal-footer'> <button type='button' class='btn btn-secondary' data-dismiss='modal'>Close</button> <a class='btn btn-danger' href='' role='button'>switch off the grid </a> </div> </div> </div> </div> <div class='container'> <div id='tutto'>";
html+="<div class='rounded-tondo grigio'> <h1><b>Traliccio</b><br> <small> check everything from here </small> </h1> </div> <br> <!-- <div class='rounded-tondo rosso'> <h3><b></b> <small> L'alimentazione proviene dalla linea elettrica </small> </h3> </div> <br>--> <div class='rounded-tondo-sopra verde'> <h3><b></b> <small> L'alimentazione proviene dalla pala eolica </small> </h3> </div> <br><br> <div class=' text-center rounded-tondo grigietto'> <div class=row> <div class=rounded-tondo> <div class='col col-12 rounded-tondo-bordo giallo'> <h3> <small> Line voltage: </small><br> <b>220V</b><br> </h3> </div> </div> <div class=rounded-tondo> <div class='col col-12 rounded-tondo-bordo giallo'> <h3> <small>Current flow: </small><br> <b>25A</b> </h3> </div> </div> <div class=rounded-tondo> <div class='col col-12 rounded-tondo-bordo giallo'> <h3> <small>Power consumption: </small><br> <b>4W</b> </h3> </div> </div> <br> </div> <div class='rounded-tondo azzurro'> <h3> Andamento della Potenza <svg xmlns='http://www.w3.org/2000/svg' version='1.1' width='100%' height='100%'> <g stroke='black'> <line x1='0%' y1='0%' x2='100%' y2='100%' stroke-width='4' /> <line x1='10%' y1='0%' x2='100%' y2='100%' stroke-width='4' /> </g> </svg> </h3> </div> </div> <br> <!-- <div class=' rounded-tondo verde'> <h3> <b> everything is fine </b> </h3> </div> --> <div class=' rounded-tondo rosso'> <h3> <b> too high power required </b> </h3> </div>";

html += "</div></div></body></html>";
  server.send(200, "text/html", html );
}


void paginaDati() {
    aggiornaValori();
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/html", codicePaginaDati() );
}


String codicePaginaDati() {
  String html = "";



  html += "<div class='rounded-tondo grigio'> <h1><b>Traliccio</b><br> <small> check everything from here </small> </h1> </div> <br> ";
  if (!inVerde) {
    html += "<div class='rounded-tondo rosso'> <h3><b></b> <small> L'alimentazione proviene dalla linea elettrica </small> </h3> </div> <br>";
  }
  else {
    html += "<div class='rounded-tondo-sopra verde'> <h3><b></b> <small> L'alimentazione proviene dalla pala eolica </small> </h3> </div> <br>";
  }
  //DATI
  html += "  <br> <div class=' text-center rounded-tondo grigietto'> <div class=row> <div class=rounded-tondo> <div class='col col-12 rounded-tondo-bordo giallo'> <h3> <small> Line voltage: </small><br> <b>";
  html += voltaggio;
  html += "V</b><br> </h3> </div> </div> <div class=rounded-tondo> <div class='col col-12 rounded-tondo-bordo giallo'> <h3> <small>Current flow: </small><br> <b>";
  html += corrente;
  html += "A</b> </h3> </div> </div> <div class=rounded-tondo> <div class='col col-12 rounded-tondo-bordo giallo'> <h3> <small>Power consumption: </small><br> <b>";
  html += potenza;
  html += "W</b> </h3> </div> </div> <br> </div> <div class='rounded-tondo azzurro'> <h3> Andamento della Potenza <svg xmlns='http://www.w3.org/2000/svg' version='1.1' width='100%' height='100%'> <g stroke='black'> ";

  //GRAFICO
  for (int i = 0; i < n_valori - 1; i++) {

    html += "<line x1='";
    html += i;
    html += "%' y1='";
    html += (int)valori_grafico[i];
    html += "%' x2='";
    html += i + 1;
    html += "%' y2='";
    html += (int)valori_grafico[i + 1];
    html += "%' stroke-width = '4' />";
  }




  html += "</g> </svg> </h3> </div> </div> <br>";





  if (!inSovraccarico) {
    html += " <div class=' rounded-tondo verde'> <h3> <b> everything is fine </b> </h3> </div>";
  }
  else {
    html += "<div class=' rounded-tondo rosso'> <h3> <b> too much power required </b> </h3> </div>";
    html += "<script> $(document).ready(function () { $('#Modal').modal('show'); }); </script>";
  }
   // if (inSovraccarico && prima_volta) {
    prima_volta = false;
//  }
  return html;
}
