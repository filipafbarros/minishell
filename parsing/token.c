/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:18:00 by keramos-          #+#    #+#             */
/*   Updated: 2024/06/27 11:57:02 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * Function to create a new token.
 * Takes the token value as an argument.
 * Returns a pointer to the new token.
 */
t_token	*create_token(char *value)
{
	t_token	*token;

	token = (t_token *)malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->value = ft_strdup(value);
	token->op = valid_op(value);
	token->next = NULL;
	return (token);
}

/*
 * Function to add a token to the end of the token list.
 * Takes a pointer to the head of the list and the token value as arguments.
 */
void	add_token(t_token **head, char *value)
{
	t_token	*new;
	t_token	*temp;

	new = create_token(value);
	if (!new)
		return ;
	if (!*head)
	{
		*head = new;
		return ;
	}
	else
	{
		temp = *head;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
}

/*
 * Function to tokenize the input string into a linked list of tokens.
 * Takes the input string as an argument.
 * Returns the head of the token list.
 */
t_token	*tokenize(char *input)
{
	t_token	*head;
	char	*token;

	head = NULL;
	while (*input)
	{
		input = skip_spaces(input);
		if (*input)
		{
			token = extract_token(&input);
			if (!token)
			{
				free_tokens(head);
				return (NULL);
			}
			add_token(&head, token);
			free(token);
		}
		input = skip_spaces(input);
	}
	return (head);
}

/*
 * Function to extract the next token from the input string.
 * Takes a pointer to the input string as an argument and updates it.
 * Returns the extracted token.
 */
char	*extract_token(char **input)
{
	char	*start;
	char	*token;
	char	*cleaned_token;
	char	quote_char;

	start = *input;
	if (**input == '\'' || **input == '\"')
	{
		quote_char = *(*input)++;
		while (**input && **input != quote_char)
			(*input)++;
		if (**input == '\0')
			return (NULL);
		if (**input)
			(*input)++;
	}
	else
	{
		while (**input && !ft_isspace(**input) && **input != '\'' && \
		**input != '\"')
			(*input)++;
	}
	token = ft_strndup(start, *input - start);
	cleaned_token = remove_quotes(token);
	free(token);
	return (cleaned_token);
}

/*
 * Function to remove quotes from a token.
 * Takes the token string as an argument.
 * Returns a new string without the quotes.
 */
char	*remove_quotes(const char *token)
{
	char	*cleaned_token;
	int		len;
	int		i;
	int		j;

	len = ft_strlen(token);
	if ((token[0] == '\'' || token[0] == '\"') && token[0] == token[len - 1])
	{
		cleaned_token = (char *)malloc(len - 1);
		if (!cleaned_token)
			return (NULL);
		i = 1;
		j = 0;
		while (i < len - 1)
			cleaned_token[j++] = token[i++];
		cleaned_token[j] = '\0';
	}
	else
		cleaned_token = ft_strndup(token, len);
	return (cleaned_token);
}

/*
		Just writing this down just in case the tokenization needs a little extra
		because of the redirection:

	Tokenization with redirection:
		The overall format used for redirection is: 
					[n]redir-op word
		The number n is an optional decimal number designating the file descriptor 
		number; the application shall ensure it is delimited from any preceding 
		text and immediately precede the redirection operator redir-op. 
		If n is quoted, the number shall not be recognized as part of the 
		redirection expression. For example:
					echo \2>a
		writes the character 2 into file a. If any part of redir-op is quoted, no redirection
		expression is recognized. For example:
					echo 2\>a
		writes the characters 2>a to standard output. The optional number, redirection 
		operator, and word shall not appear in the arguments provided to the command 
		to be executed (if any).
*/