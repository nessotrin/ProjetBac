<!DOCTYPE html> <!-- ça c'est pour dire que c'est du html-->

<!-- permet d'accéder à la base de donnée, de se connecter et de récupérer les médicaments -->
<?php
include 'database.php';
$socket = connect();
getMedsInfo($socket);
?>

<html>
    <head>  <!-- en anglais, tête -->
        <meta charset="utf-8" /> <!-- ça c'est pour dire quel encodage de caractère on utilise -->
          
		  <link rel="stylesheet" media="screen" title="A.D.S. Centre de controle" 
		             href="index.css" />
					 
		<title>A.D.S. Centre de controle</title><!-- en anglais...non je ne le dis pas --> 
    </head>

    <body> <!-- le corps du tableur/de la page -->
	
	<link href='https://fonts.googleapis.com/css?family=Cookie' rel='stylesheet' type='text/css'><!--balise pour rajouter la police Cookie de Google Fonts-->

	<div class="titrePage">
		<h1>BOITE A PHARMACIE</h1>  <!-- Titre s'affichant sur la page et non sur le titre au niveau de l'onglet -->       
	</div>	
	<table class="styleTable">		
		<tr>
			<td class="leftScreenZone">
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
				<div class="historiqueZone">		
					<h2 class="titreHistorique">Historique</h2>
					<div class= "historiqueTexte">
 Lorem ipsum dolor sit amet, consectetur adipiscing elit. Donec in dictum diam. Ut quam erat, placerat eget orci a, hendrerit vulputate elit. Suspendisse sit amet mauris vitae ligula interdum hendrerit. Donec at ornare nunc, et porttitor mi. Etiam porttitor, leo non sagittis aliquam, quam enim feugiat magna, nec aliquet velit diam quis tortor. Cras nec accumsan risus, in facilisis ipsum. Quisque euismod vitae nisi ac ornare. Curabitur efficitur faucibus elit at ornare.

Mauris ornare leo mauris, sed lobortis felis hendrerit ac. Maecenas id dolor quis ex posuere fermentum. Fusce in nunc sed libero imperdiet condimentum vitae ac urna. Pellentesque commodo quam sed aliquam sollicitudin. Ut vitae sagittis velit. Fusce sagittis suscipit massa ac scelerisque. Sed auctor quis sem ut mattis.

Aenean et libero sodales, congue nunc a, aliquet arcu. Duis ultrices accumsan turpis sit amet mollis. Pellentesque ut congue ipsum, id imperdiet tellus. Maecenas condimentum nibh non magna rutrum congue. Sed turpis mauris, laoreet a mauris non, viverra vehicula arcu. Pellentesque venenatis nulla non nunc rhoncus laoreet. Morbi vel nisl sapien. Mauris laoreet turpis ut massa pretium pretium. Vivamus massa nulla, molestie non convallis id, dignissim in mauris. Cras ultricies neque nec fermentum volutpat. Proin est felis, consectetur at augue at, dapibus dictum tellus. Quisque convallis pharetra dignissim. Nulla laoreet feugiat purus ut pellentesque. Vestibulum justo lacus, ornare a dignissim vitae, molestie in lorem. Maecenas ac tincidunt magna, vel accumsan leo. Proin ac est auctor, congue sapien at, rhoncus lectus.

Donec lacinia ipsum id nisl pretium, quis semper diam rhoncus. Pellentesque tincidunt pretium massa, vel rutrum ligula porttitor sit amet. Nunc maximus nisi eros, ut placerat nisi mollis ac. Duis at blandit purus, vitae convallis tellus. Vivamus molestie sollicitudin massa vel gravida. Sed eu erat non tortor dictum lobortis sed eget erat. Donec porta elit neque, nec malesuada eros facilisis at. Praesent ante ligula, rutrum eget purus vel, eleifend iaculis mauris.

Praesent in varius ex. Quisque magna lectus, mattis at eleifend eu, mattis eu velit. Aenean feugiat sapien in orci rhoncus aliquet. Donec pretium libero eget euismod pellentesque. Mauris eget placerat justo. Orci varius natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. Vestibulum et ullamcorper enim, a blandit turpis. Donec faucibus neque eu viverra suscipit. Mauris vel lacus in leo varius tempor ut at lorem. Aliquam a ullamcorper lacus, quis consectetur lacus. Quisque fermentum gravida quam euismod congue. Interdum et malesuada fames ac ante ipsum primis in faucibus. 					</div>
				</div>

			</td>
			<td class="screenMiddleSeparator">
				<div class="screenMiddleSeparatorLine">
					&nbsp;
				</div>
			</td>
			<td class="rightScreenZone">
				<div class= "medocZone">

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
								echo "<td class=\"addLeftSpacing\">";
									echo "<div class=\"medocCount\">";
										echo getMedCount($socket, $idMed); 
									echo "</div>";
								echo "</td>";
							echo "</tr>";
						}
						?>
					</table>
				</div>
			</td>
		</tr>

	</table>	
		
    </body>
</html>

