<!DOCTYPE html> <!-- ça c'est pour dire que c'est du html-->

<?php
include 'database.php';
$socket = connect();
getMedsInfo($socket);
?>

<html>
    <head>  <!-- en anglais, tête -->
        <meta charset="utf-8" /> <!-- ça c'est pour dire quel encodage de caractère on utilise -->
          
		  <link rel="stylesheet" media="screen" title="fiche rentree Issert Erika" 
		             href="index.css" />
					 
		<title>Fiche de rentrée</title><!-- en anglais...non je ne le dis pas --> 
    </head>

    <body> <!-- le corps du tableur/de la page -->
	
	<link href='https://fonts.googleapis.com/css?family=Cookie' rel='stylesheet' type='text/css'><!--balise pour rajouter la police Cookie de Google Fonts-->

	<div class="titrePage">
		<h1>BOITE A PHARMACIE</h1>  <!-- Titre s'affichant sur la page et non sur le titre au niveau de l'onglet -->       
	</div>	
		
	<div class= "medecinZone">
		<table class="medecinTable" >
			<tr>
				<td>
					<div class= "medecinBubble" style="background-image:url(http://25.media.tumblr.com/tumblr_m0oxdjBC5R1rrugkyo1_500.jpg);">
						<div class= "medecinBubbleOverlay">
							<div class= "medecinBubbleText">							
								<?php echo "FUNCTION1"; ?>
							</div>						
						</div>
					</div>
					<div class= "medecinNom">
						<?php echo "MEDECIN1"; ?>
					</div>
				</td>
				<td>
					<div class= "medecinBubble" style="background-image:url(http://cdn0.lostateminor.com/wp-content/uploads/2013/03/Cat-Scientist-2-650x620.jpg);">
						<div class= "medecinBubbleOverlay">
							<div class= "medecinBubbleText">							
								<?php echo "FUNCTION2"; ?>
							</div>						
						</div>
					</div>
					<div class= "medecinNom">
						<?php echo "MEDECIN2"; ?>
					</div>
				</td>
				<td>
					<div class= "medecinBubble" style="background-image:url(http://images.nymag.com/news/business/boom-brands/business130930_grumpycat_2_560.jpg);">
						<div class= "medecinBubbleOverlay">
							<div class= "medecinBubbleText">							
								<?php echo "FUNCTION3"; ?>
							</div>						
						</div>
					</div>
					<div class= "medecinNom">
						<?php echo "MEDECIN3"; ?>
					</div>
				</td>
				<td>
					<div class= "medecinBubble" style="background-image:url(http://data.whicdn.com/images/38807186/large.jpg);">
						<div class= "medecinBubbleOverlay">
							<div class= "medecinBubbleText">							
								<?php echo "FUNCTION4"; ?>
							</div>						
						</div>
					</div>
					<div class= "medecinNom">
						<?php echo "MEDECIN4"; ?>
					</div>
				</td>
			</tr>
		</table>
	</div>
	<div class= "medocZone">
		<table class="medocStyleTable">
			<tr>
				<td class="medocSeparator">
					&nbsp;
				</td>
				<td>		
					<h2 class="titreMedoc">Medicaments</h2>
					<table class="medocTable" >
						<?php 
						for ($idMed = 0 ; $idMed < $medCount ; $idMed++)
						{
							echo "<tr>";
								echo "<td>";
									echo "<div class=\"medocImg\">";
										echo "<img src=" . getMedImg($socket, $idMed) . " heigth=100 width=100>"; 
									echo "</div>";	
								echo "</td>";
								echo "<td class=\"addLeftSpacing\">";
									echo "<div class=\"medocNom\">";
										echo $medNames[$idMed]; 
									echo "</div>";
								echo "</td>";
							echo "</tr>";
						}
						?>
					</table>
				</td>
			</tr>
		</table>	
	</div>

	<div class="historiqueZone">		
		<h2 class="titreHistorique">Historique</h2>
		<div class= "historiqueTexte">
Atque, ut Tullius ait, ut etiam ferae fame monitae plerumque ad eum locum ubi aliquando pastae sunt revertuntur, ita homines instar turbinis degressi montibus impeditis et arduis loca petivere mari confinia, per quae viis latebrosis sese convallibusque occultantes cum appeterent noctes luna etiam tum cornuta ideoque nondum solido splendore fulgente nauticos observabant quos cum in somnum sentirent effusos per ancoralia, quadrupedo gradu repentes seseque suspensis passibus iniectantes in scaphas eisdem sensim nihil opinantibus adsistebant et incendente aviditate saevitiam ne cedentium quidem ulli parcendo obtruncatis omnibus merces opimas velut viles nullis repugnantibus avertebant. haecque non diu sunt perpetrata.

Hanc regionem praestitutis celebritati diebus invadere parans dux ante edictus per solitudines Aboraeque amnis herbidas ripas, suorum indicio proditus, qui admissi flagitii metu exagitati ad praesidia descivere Romana. absque ullo egressus effectu deinde tabescebat immobilis.

Vide, quantum, inquam, fallare, Torquate. oratio me istius philosophi non offendit; nam et complectitur verbis, quod vult, et dicit plane, quod intellegam; et tamen ego a philosopho, si afferat eloquentiam, non asperner, si non habeat, non admodum flagitem. re mihi non aeque satisfacit, et quidem locis pluribus. sed quot homines, tot sententiae; falli igitur possumus.

Quod opera consulta cogitabatur astute, ut hoc insidiarum genere Galli periret avunculus, ne eum ut praepotens acueret in fiduciam exitiosa coeptantem. verum navata est opera diligens hocque dilato Eusebius praepositus cubiculi missus est Cabillona aurum secum perferens, quo per turbulentos seditionum concitores occultius distributo et tumor consenuit militum et salus est in tuto locata praefecti. deinde cibo abunde perlato castra die praedicto sunt mota.

Inter quos Paulus eminebat notarius ortus in Hispania, glabro quidam sub vultu latens, odorandi vias periculorum occultas perquam sagax. is in Brittanniam missus ut militares quosdam perduceret ausos conspirasse Magnentio, cum reniti non possent, iussa licentius supergressus fluminis modo fortunis conplurium sese repentinus infudit et ferebatur per strages multiplices ac ruinas, vinculis membra ingenuorum adfligens et quosdam obterens manicis, crimina scilicet multa consarcinando a veritate longe discreta. unde admissum est facinus impium, quod Constanti tempus nota inusserat sempiterna.
		</div>
	</div>
		
    </body>
</html>

