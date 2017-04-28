<!DOCTYPE html>
<?php
include 'database.php';
$socket = connect();
?>

<?php
include 'page_head.php'
?>

<td class="erreursScreenZone">


<table>
	<tr>
<?php
$nombreMed = getTotalMedsCount($socket);

for($id = 0 ; $id < $nombreMed ; $id++)
{
			echo '<td>';
				echo '<div class="ajoutsuppDiv" >';
					echo '<img class="ajoutsuppDivImg" src="' ,  getMedImg($socket, $id) ,'">';
					echo '<div class="ajoutsuppOverlay" >';
						echo '<a href="suppmed.php?id=',$id,'" >' ;
						echo '<img class="ajoutsuppOverlayImg" src="cross.png">';
						echo '</a>';
					echo '</div>';

				echo '</div>';
			echo '</td>';
}
		echo '<td>';
			echo '<a href="ajoutmed.php" >' ;
			echo '<img class="ajoutsuppAjoutImg" src="ajout.png">';
			echo '</a>';
		echo '</td>';

?>
	</tr>
<?php
$nombreHumain = getTotalHumanCount($socket);

for($id = 0 ; $id < $nombreHumain ; $id++)
{
			echo '<td>';
				echo '<div class="ajoutsuppDiv" >';
					echo '<img class="ajoutsuppDivImg" src="' ,  getHumanImg($socket, $id) ,'">';
					echo '<div class="ajoutsuppOverlay" >';
						echo '<a href="suppmed.php?id=',$id,'" >' ;
						echo '<img class="ajoutsuppOverlayImg" src="cross.png">';
						echo '</a>';
					echo '</div>';

				echo '</div>';
			echo '</td>';
}
		echo '<td>';
			echo '<a href="ajouthumain.php" >' ;
			echo '<img class="ajoutsuppAjoutImg" src="ajout.png">';
			echo '</a>';
		echo '</td>';

?>

	<tr>
	
	</tr>

</table>


</td>
						
<?php
include 'page_foot.php'
?>
