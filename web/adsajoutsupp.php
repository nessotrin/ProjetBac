<!DOCTYPE html>
<?php
include 'database.php';
$socket = connect();
getMedsInfo($socket);
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
                    <h1>Paramètres</h1>
                    Lorem ipsum dolor sit amet, consectetur adipiscing elit. Donec in dictum diam. Ut quam erat, placerat eget orci a, hendrerit vulputate elit. Suspendisse sit amet mauris vitae ligula interdum hendrerit. Donec at ornare nunc, et porttitor mi. Etiam porttitor, leo non sagittis aliquam, quam enim feugiat magna, nec aliquet velit diam quis tortor. Cras nec accumsan risus, in facilisis ipsum. Quisque euismod vitae nisi ac ornare. Curabitur efficitur faucibus elit at ornare.

Mauris ornare leo mauris, sed lobortis felis hendrerit ac. Maecenas id dolor quis ex posuere fermentum. Fusce in nunc sed libero imperdiet condimentum vitae ac urna. Pellentesque commodo quam sed aliquam sollicitudin. Ut vitae sagittis velit. Fusce sagittis suscipit massa ac scelerisque. Sed auctor quis sem ut mattis.

Aenean et libero sodales, congue nunc a, aliquet arcu. Duis ultrices accumsan turpis sit amet mollis. Pellentesque ut congue ipsum, id imperdiet tellus. Maecenas condimentum nibh non magna rutrum congue. Sed turpis mauris, laoreet a mauris non, viverra vehicula arcu. Pellentesque venenatis nulla non nunc rhoncus laoreet. Morbi vel nisl sapien. Mauris laoreet turpis ut massa pretium pretium. Vivamus massa nulla, molestie non convallis id, dignissim in mauris. Cras ultricies neque nec fermentum volutpat. Proin est felis, consectetur at augue at, dapibus dictum tellus. Quisque convallis pharetra dignissim. Nulla laoreet feugiat purus ut pellentesque. Vestibulum justo lacus, ornare a dignissim vitae, molestie in lorem. Maecenas ac tincidunt magna, vel accumsan leo. Proin ac est auctor, congue sapien at, rhoncus lectus.

Donec lacinia ipsum id nisl pretium, quis semper diam rhoncus. Pellentesque tincidunt pretium massa, vel rutrum ligula porttitor sit amet. Nunc maximus nisi eros, ut placerat nisi mollis ac. Duis at blandit purus, vitae convallis tellus. Vivamus molestie sollicitudin massa vel gravida. Sed eu erat non tortor dictum lobortis sed eget erat. Donec porta elit neque, nec malesuada eros facilisis at. Praesent ante ligula, rutrum eget purus vel, eleifend iaculis mauris.

Praesent in varius ex. Quisque magna lectus, mattis at eleifend eu, mattis eu velit. Aenean feugiat sapien in orci rhoncus aliquet. Donec pretium libero eget euismod pellentesque. Mauris eget placerat justo. Orci varius natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. Vestibulum et ullamcorper enim, a blandit turpis. Donec faucibus neque eu viverra suscipit. Mauris vel lacus in leo varius tempor ut at lorem. Aliquam a ullamcorper lacus, quis consectetur lacus. Quisque fermentum gravida quam euismod congue. Interdum et malesuada fames ac ante ipsum primis in faucibus.

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