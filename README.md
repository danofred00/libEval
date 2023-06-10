# Un evalueur pour les expressions arithmetiques [Danofred00](https://github.com/danofred00)


## Somaire
1. <a href="#intro">Introduction</a>
2. <a href="#usage">Utilisation</a>

## <h2 id="intro">Introduction</h2>

Cette librairie est totalement opensource, vous pouvez donc l'inclure dans tous vos differents projets sans vous soussiez de la license. De plus, son utilisation est assez simple (nous verrons cela dans les prochaines lignes).

## <h2 id="usage">Utilisation</h2>

Cette mini lib vous fourni une seule fonction qui vous devez utiliser pour tout, notament la fonction eval() qui se trouve dans le fichier d'entete calculator.h

Pour integrer ma librairie dans votre code, vous pouvez la lié comme librairie statique, ou bien comme librairie dynamique (chose facile si vous savez utiliser cmake).

Si vous n'avez pas de connaissance dans cmake c'est pas grave, je vous envoie sur ma [chaine youtube](https://youtube.com/harptutos) où une vidéo vous expliquand les étapes de compilation d'un programme vous est brièvement présenter.

### Bonus
En bonus, j'ai créer une sorte de mini interface pour les tests que vous allez surement retrouver dans le repertoire test de ce dépot. Une fois compiler, son exécution vous permet de tester de manuellement la fonction d'évaluation que je vous fourni.

```sh
    $>./test "5+2+1*3" # test
    $> final result = 10 # output
```

Sur ce, je vous prie de bienvouloir faire des retours apres vos tests, cela me pertant d'améliorer le fonction de cette librairie.

Thanks.