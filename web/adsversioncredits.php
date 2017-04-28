<!DOCTYPE html>
<?php
include 'database.php';
$socket = connect();
?>
<html>
    <head>
        <meta charset="utf-8" />
        <link rel="stylesheet" href="adsmenu.css" />
        <title>ADS Automatic Drugs-Dispensing System</title>
    </head>
    
    <body>
        <div id="bloc_page">
            <header>
                <div id="banniere">
                </div>
            </header>
            
            <section>

				<article>
                    <h1>Version</h1>
					<div id="date">
						<SCRIPT LANGUAGE="JavaScript">
							var maintenant=new Date();
							var jour=maintenant.getDate();
							var mois=maintenant.getMonth()+1;
							var an=maintenant.getFullYear();
							document.write("Vu le ",jour,"/",mois,"/",an,".");
						</SCRIPT>
						<br>
						V 0.0.0.1
					</div>
					<h1>Crédits</h1>
					<h2>Staff</h2>
					

                </article>
				<aside>
                    <h1>Sommaire</h1>
					<ul>
						<li><a href="adsmenu.php">Menu principal</a></li>
						<li><a href="adsparametres.php">Paramètres</a></li>
						<li><a href="adserreurslog.php">Erreurs et logs</a></li>
						<li><a href="adsversioncredits.php">Version et crédits</a></li>
					</ul>
                </aside>
            </section>
            
            <footer>
				<?php
				if (0)
				{
					echo '<img scr="https://upload.wikimedia.org/wikipedia/commons/thumb/9/94/Jersey_red.svg/50px-Jersey_red.svg.png">';
				}
				else
				{
					echo '<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/1/1b/Jersey_pink.svg/50px-Jersey_pink.svg.png">';
					
				}
				?>
			</footer>
        </div>
    </body>
</html>
