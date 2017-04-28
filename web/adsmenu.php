<!DOCTYPE html>
<?php
include 'database.php';
$socket = connect();
?>

<?php
include 'page_head.php'
?>

<td class="leftScreenZone">
	<div class= "medecinZone">
		<table class="medecinTable" >
			<tr>
			<?php 
            $humanCount = getTotalHumanCount($socket);
			for ($id = 0 ; $id < $humanCount ; $id++)
			{
					echo'<td>';
					echo '<div class= "medecinBubble" style="background-image:url(' , getHumanImg($socket,$id) , ');">;';
						echo'<div class= "medecinBubbleOverlay">';
							echo '<div class= "medecinBubbleText">';							
							echo '</div>';						
						echo'</div>';
					echo '</div>';
					echo '<div class= "medecinNom">';
						echo getHumanName($socket,$id);
					echo '</div>';
				echo '</td>';
			}
			?>
			</tr>
		</table>
	</div>
	<div class="historiqueZone">		
		<h2 class="titreHistorique">Historique</h2>
			<div class= "historiqueTexte">
				<?php 
				include 'historyHelper.php'
				?>
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
            $medsCount = getTotalMedsCount($socket);
			for ($idMed = 0 ; $idMed < $medsCount ; $idMed++)
			{
				echo "<tr>";
					echo "<td>";
						echo "<div class=\"medocImg\">";
							echo "<img src=" . getMedImg($socket, $idMed) . " heigth=100 width=100>"; 
						echo "</div>";	
					echo "</td>";
					echo "<td class=\"addLeftSpacing\">";
						echo "<div class=\"medocNom\">";
							echo getMedName($socket, $idMed); 
						echo "</div>";
					echo "</td>";
					echo "<td class=\"addLeftSpacing\">";
						echo "<div class=\"medocCount\">";
							echo getMedCount($socket, $idMed); 
						echo "</div>";
					echo "</td>";
				echo "</tr>";
			}
			?>
			<tr>
				<td>
					<div class="iconparam">
						<a href="adsparametres.php"><img src="https://cdn4.iconfinder.com/data/icons/developer-set-3/128/settings-128.png"></a>
					</div>
				</td>	
			</tr>
		</table>
	</div>
</td>
						
<?php
include 'page_foot.php'
?>
