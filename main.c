/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keezgi <keezgi@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*-                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 12:30:52 by keezgi            #+#    #+#             */
/*   Updated: 2026/01/25 17:40:37 by keezgi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    print_map_list(t_list *map)
{
    t_list  *tmp;
    int     i;

    tmp = map;
    i = 0;
    printf("\n------- MAP LIST CONTENT -------\n");
    while (tmp)
    {
        printf("Node [%d] | Width: %zu | Length: %zu | Content: %s", 
               i, tmp->width, tmp->length, tmp->content);
        if (tmp->content && tmp->content[ft_strlen(tmp->content) - 1] != '\n')
            printf("\n");

        tmp = tmp->next;
        i++;
    }
    printf("--------------------------------\n");
}

void print_map_debug(char **map)
{
    int i;

    i = 0;
    if (!map)
    {
        printf("Error: Map is NULL\n");
        return ;
    }
    printf("\n--- MAP DEBUG START ---\n");
    while (map[i])
    {
        // Eğer satır sonlarında hala \n varsa alt satıra kaymış gibi görünebilir.
        // Amaç satırın bittiği yeri görmektir.
        printf("[%d] |%s|\n", i, map[i]);
        i++;
    }
    printf("--- MAP DEBUG END ---\n\n");
}


int    arg_parse(char *str)
{
    size_t pos;

    pos = ft_strlen(str);
    if (pos < 5 || ft_strcmp(&str[pos - 4] , ".cub"))
    {
        print_err("File extension doesn't end with .cub");
        exit(1);
    }
    return (0);
}

int main (int ac, char **av)
{
    t_game game;
    if (ac == 2)
    {
        arg_parse(av[1]);
        read_file(&game ,av[1]);
        if(!handle_map(&game))
        {
            // free hata kontrolu eklenecek (garbage collector freesi)
            return (1);
        }
        print_map_debug(game.matrix_map);
    }
    else
    {
        print_err("Program must take 2 argument!");
        return (1);
    }
}

/*


 ===================================================================

 
C0,0,255 => opsiyonel olarak C sonrası boşluk karakteri kontrol atarsın ----------------------> ÇOKTA GEREKLİ DEĞİL BİLMİYORUM

?=======================================================================

BABAAAA EA ./path_to_the_east_texture./path_to_the_west_texture bu mevzuyu unutma (Arif)

?=======================================================================


 % ./cub3d map/map.cub
Error
Invalid line or missing textures on file
keezgi@k1m23s03 ~/Masaüstü/cub3d => opsiyonel hata durumunu color olarak ayarlayabilirsin -----------------> HATA DURUMLARI MESAJLAR


?=======================================================================


Map content okurken content olmayan bir line error vermeli subjecte yazıyor 
◦ Except for the map content, each type of element can be separated by one or ------------------------>MAP NEWLİNELERLE AYRILMIYOR ARTIK , AYRICA MAPIN SONUNDADA NL EKLEYEMİYORSUN
more empty lines
sadece satır için geçerli


===============================================================


1111111111111110
1000000000001111
10000000S0001 1 1               => OPSİYONEL birkaç kişinin fikrini alırsın
111111111111101
1111111111111111

=============================================

SO ../path_to_the_south_texture Bunu da unutmayın arif
SO ././path_to_the_south_texture Bunu da unutmayın arif

=============================================
*/