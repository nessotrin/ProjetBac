						</tr>

					</table>
                </article>
            </section>
            
            <footer>
				<?php
					if (getEtatPorte($socket) == false)
					{
						echo '<img width=50px height=50xp src="http://image.noelshack.com/fichiers/2017/19/1494486942-bouton-rouge.png">';
					}
					else
					{
						echo '<img width=50px height=50xp src="http://image.noelshack.com/fichiers/2017/19/1494486943-bouton-vert.png">';
					}
				?>
			</footer>
        </div>
    </body>
</html>
