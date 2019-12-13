/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_hundler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 16:43:14 by fbouibao          #+#    #+#             */
/*   Updated: 2019/12/10 16:45:19 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


char *get_s_p_s(char *val, char *prec)
{
  char *str_c;
  int i;
 
  if (!(str_c = malloc(atoi(prec) + 1)))
    return (NULL);
  str_c[atoi(prec)] = '\0';
  i = -1;
  
  while (++i < (int)ft_strlen(val) && i < atoi(prec))
    str_c[i] = val[i];
  return (str_c);
}

void str_spf_s(va_list ap, t_list *tmp)
{
  char *flgs;
  char flg;
  char *width;
  char *val;
  char *prec;
  char *str_c;
  int i = -1, j;

  flgs = tmp->flg;
  if (flgs[0] == '\0')
  {
    tmp->str = va_arg(ap, char*);
    return ;
  }

  flg = cut_flg(flgs, &i);
  width = cut_width(ap, flgs, &i, &flg);
  prec = cut_prec(ap, flgs, &i);

  val = va_arg(ap, char*);

  
  // width


if (atoi(width) != -1)
{   
  if ((int)ft_strlen(val) >= atoi(width) && atoi(prec) == -1)
  {
    tmp->str = malloc(ft_strlen(val) + 1);
    tmp->str[ft_strlen(val)] = '\0';
  }
  else
  {
    tmp->str = malloc(atoi(width) + 1);
    tmp->str[atoi(width)] = '\0';
  }
    (flg == '0') ? memset(tmp->str, '0', atoi(width)) : memset(tmp->str, ' ', atoi(width));

  i = atoi(width) - 1;
  j = ft_strlen(val) - 1;
  if ((int)ft_strlen(val) >= atoi(width) && atoi(prec) == -1)
    while (j >= 0)
    {
      tmp->str[j] = val[j];
      j--;
    }
  else if ((int)ft_strlen(val) < atoi(width) && flg == '-')
  {
    i = 0;
    j = 0;
    while (i < (int)ft_strlen(val))
    {
      tmp->str[i++] = val[j];
      j++;
    }
  }
  else if ((int)ft_strlen(val) < atoi(width))
    while (j >= 0)
    {
      tmp->str[i--] = val[j];
      j--;
    }
}
//end width

// prec
if (atoi(prec) >= 0 && atoi(prec) > atoi(width) && atoi(width) < (int)ft_strlen(val))
{
  str_c = get_s_p_s(val, prec);
  free(tmp->str);
  tmp->str = str_c;
}
else if (flg == '-' && atoi(prec) >= 0)
{
  i = atoi(width);
    while (--i >= 0)
        tmp->str[i] = ' ';
    str_c = get_s_p_s(val, prec);
    i = -1;
    while (++i < (int)ft_strlen(str_c))
      tmp->str[i] = str_c[i];
}
else if (atoi(prec) >= 0)
{
  i = atoi(width);
    while (--i >= 0)
        tmp->str[i] = ' ';
    str_c = get_s_p_s(val, prec);
    i = atoi(width);
    j = ft_strlen(str_c);
    while (--j >= 0)
      tmp->str[--i] = str_c[j];
}

//3
//1



// end prec


}