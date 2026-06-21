#define _CRT_SECURE_NO_WARNINGS
/***************************************************************/
/*                           INCLUDES                          */
/***************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <assert.h>
#include <stdarg.h>
#include <math.h>
#include <limits.h>


/***************************************************************/
/*                         DEFINITIONS                         */
/***************************************************************/

#define VERBOSE_LEVEL    (1)

/* divergence iteration threshold for gauss-seidal */
#define DIVERGENCE_THRESHOLD  (5)
#define ZERO_THRESHOLD        (1e-10)

#define bool  int
#define true  (1)
#define false (0)

#define NOT_EXIST  (-1)

#define MIN_CAPACITY   (16)   /* minimum element count */
#define MAX_BUFFER     (1024)
#define MAX_METHOD     (10)   /* Number of method */

#define INDEX_CHAR_PLUS    (0)
#define INDEX_CHAR_MINUS   (1)
#define INDEX_CHAR_MUL     (2)
#define INDEX_CHAR_DIV     (3)
#define INDEX_CHAR_EXP     (4)

#define INDEX_CHAR_LPAREN   (5)
#define INDEX_CHAR_RPAREN   (6)
#define INDEX_CHAR_COMMA    (7)
#define INDEX_CHAR_EQUATION (8)

#define INDEX_FUNC_SIN     (0)
#define INDEX_FUNC_COS     (1)
#define INDEX_FUNC_TAN     (2)
#define INDEX_FUNC_COT     (3)
#define INDEX_FUNC_CSC     (4)
#define INDEX_FUNC_SEC     (5)
#define INDEX_FUNC_ARCSIN  (6)
#define INDEX_FUNC_ARCCOS  (7)
#define INDEX_FUNC_ARCTAN  (8)
#define INDEX_FUNC_ARCCOT  (9)
#define INDEX_FUNC_ARCCSC  (10)
#define INDEX_FUNC_ARCSEC  (11)
#define INDEX_FUNC_LOG     (12)
#define INDEX_FUNC_LN      (13)

#define ASSOC_LEFT_TO_RIGHT   (0)
#define ASSOC_RIGHT_TO_LEFT   (1)

#define INDEX_OP_COMMA        (0)
#define INDEX_OP_BINARY_PLUS  (1)
#define INDEX_OP_BINARY_MINUS (2)
#define INDEX_OP_MUL          (3)
#define INDEX_OP_DIV          (4)
#define INDEX_OP_UNARY_PLUS   (5)
#define INDEX_OP_UNARY_MINUS  (6)
#define INDEX_OP_EXP          (7)
#define INDEX_OP_FUNC         (8)
#define INDEX_OP_PAREN        (9)

#define PRECEDENCE_COMMA        (1)
#define PRECEDENCE_BINARY_PLUS  (2)
#define PRECEDENCE_BINARY_MINUS (2)
#define PRECEDENCE_MUL          (3)
#define PRECEDENCE_DIV          (3)
#define PRECEDENCE_UNARY_PLUS   (4)
#define PRECEDENCE_UNARY_MINUS  (4)
#define PRECEDENCE_EXP          (4)
#define PRECEDENCE_FUNCTION     (6)
#define PRECEDENCE_PAREN        (7)

#define DEFAULT_EPSILON    (0.000001)

/***************************************************************/
/*                            MACROS                           */
/***************************************************************/

#define UNUSED_PARAMETER(parameter) \
do                                  \
{                                   \
	(void)(parameter);              \
}while(0)

#define CHECK_PARAMETERS(condition, action)              \
do                                                       \
{                                                        \
	assert(!(condition));                                \
	if((condition))                                      \
	{                                                    \
		fprintf(stderr, "Parameters are invalid\n");     \
		action;                                          \
	}                                                    \
}while(0)

#define CHECK_TOKENLIST_VALIDANCE(lst, action)                 \
do                                                             \
{                                                              \
	bool isNotValid = ((lst) == NULL) ||                       \
		(((lst)->capacity == 0) ^ ((lst)->tokens == NULL)) ||  \
		((lst)->capacity < (lst)->length);                     \
	assert(!isNotValid);                                       \
	if(isNotValid)                                             \
	{                                                          \
		fprintf(stderr, "TokenList is invalid\n");             \
		action;                                                \
	}                                                          \
}while(0)

#define CHECK_VARIABLE_VALIDANCE(var, action)             \
do                                                        \
{                                                         \
	bool isNotValid = ((var) == NULL) ||                  \
		(((var)->length == 0) ^ ((var)->tokens == NULL)); \
	assert(!isNotValid);                                  \
	if(isNotValid)                                        \
	{                                                     \
		fprintf(stderr, "Variable is invalid\n");         \
		action;                                           \
	}                                                     \
}while(0)

#define CHECK_VARLIST_VALIDANCE(vlst, action)             \
do                                                        \
{                                                         \
	bool isNotValid = ((vlst) == NULL) ||                 \
		(((vlst)->length == 0) ^ ((vlst)->var == NULL));  \
	assert(!isNotValid);                                  \
	if(isNotValid)                                        \
	{                                                     \
		fprintf(stderr, "VariableList is invalid\n");     \
		action;                                           \
	}                                                     \
}while(0)

#define CHECK_MATRIX_VALIDANCE(mat, action)               \
do                                                        \
{                                                         \
	bool isNotValid = ((mat) == NULL) ||                  \
		(((mat)->row == 0) ^ ((mat)->data == NULL)) ||    \
		(((mat)->col == 0) ^ ((mat)->data == NULL));      \
	assert(!isNotValid);                                  \
	if(isNotValid)                                        \
	{                                                     \
		fprintf(stderr, "Matrix is invalid\n");           \
		action;                                           \
	}                                                     \
}while(0)

#define CHECK_VECTOR_VALIDANCE(v, action)                 \
do                                                        \
{                                                         \
	bool isNotValid = ((v) == NULL) ||                    \
		(((v)->n == 0) ^ ((v)->data == NULL));            \
	assert(!isNotValid);                                  \
	if(isNotValid)                                        \
	{                                                     \
		fprintf(stderr, "Vector is invalid\n");           \
		action;                                           \
	}                                                     \
}while(0)

#define CHECK_ALLOCATION(ptr, action)                    \
do                                                       \
{                                                        \
	assert((ptr));                                       \
	if((ptr) == NULL)                                    \
	{                                                    \
		perror("Allocation error");                      \
		action;                                          \
	}                                                    \
}while(0)

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))


/***************************************************************/
/*                       DATA STRUCTURES                       */
/***************************************************************/

typedef char *String;

struct Variable;

typedef enum Method
{
	METHOD_EXIT = -1,
	METHOD_BISECTION,
	METHOD_REGULA_FALSI,
	METHOD_NEWTON_RAPHSON,
	METHOD_MATRIX_INVERSE,
	METHOD_CHOLESKY,
	METHOD_GAUSS_SEIDAL,
	METHOD_NUMERICAL_derivative,
	METHOD_SIMPSON,
	METHOD_TRAPEZOID,
	METHOD_GREGORY_INTERPOLATION
}Method;

typedef enum TokenType
{
	TOKEN_INVALID,
	TOKEN_CONSTANT,		/* 3 5 10 12314 */
	TOKEN_VARIABLE,		/* any valid variable name */
	TOKEN_LPAREN,		/* ( */
	TOKEN_RPAREN,		/* ) */
	TOKEN_COMMA,		/* , */
	TOKEN_OPERATOR,		/* "* + - / ^" */
	TOKEN_FUNCTION,		/* sin, cos, tan, cot, ... */
	TOKEN_EQUAL         /* = */
}TokenType;

typedef struct OrderOfOperation
{
	unsigned precedence : 7;
	unsigned associativity : 1;
}OrderOfOperation;

typedef struct TokenData
{
	double           val;           /* only valid in TOKEN_CONSTANT tokens */
	size_t           varIndex;      /* only valid in TOKEN_VARIABLE index in VarList table */
	OrderOfOperation order;         /* only valid ind TOKEN_OPERATOR or TOKEN_FUNCTION */
	unsigned         paramCount: 8; /* only valid ind TOKEN_OPERATOR or TOKEN_FUNCTION */
	double           (*fp) ();      /* only valid in TOKEN_OPERATOR and TOKEN_FUNCTION */
	
}TokenData;


typedef struct Token
{
	TokenType	type;
	TokenData	data;
	String		s;     /* dynamicly created string, free after use */
}Token;

typedef struct TokenList
{
	Token    *tokens;
	size_t    length;
	size_t    capacity;
}TokenList;

typedef struct Variable
{
	Token **tokens;
	size_t  length;       /* count of tokens */
	String  name;
	double  value;
	bool    isConstant;   /* true for 'e' or 'pi' */
}Variable;

typedef struct VariableList
{
	Variable *var;
	size_t    length;
}VarList;


typedef struct Matrix
{
	size_t   row, col;
	double **data;
}Matrix;

typedef struct Vector
{
	size_t n;
	double *data;
}Vector;

/***************************************************************/
/*                     FUNCTION PROTOTYPES                     */
/***************************************************************/

bool token_list_init          (TokenList *lst);
bool token_list_deinit        (TokenList *lst);
bool token_list_is_empty      (TokenList *lst);
bool token_list_add           (TokenList *lst, Token token);
bool token_list_insert        (TokenList *lst, Token token, size_t index);
bool token_list_get_last      (TokenList *lst, Token *token);
bool token_list_remove_at     (TokenList *lst, size_t index);
bool token_list_remove_last   (TokenList *lst);
bool token_list_remove        (TokenList *lst, Token *token);
bool token_list_reserve       (TokenList *lst, size_t capacity);
bool token_list_shrink_to_fit (TokenList *lst);

bool variable_init      (Variable *var, String varName);
bool variable_deinit    (Variable *var);
bool variable_add_token (Variable *var, Token *token);

bool       var_list_init                (VarList *vlst);
bool       var_list_deinit              (VarList *vlst);
int        var_list_get_index           (VarList *vlst, String varName);
bool       var_list_add_predefined_vars (VarList *vlst);
bool       var_list_add                 (VarList *vlst, Variable var);
size_t     var_list_non_const_count     (VarList *vlst);
Variable  *var_list_get_first_non_const (VarList *vlst);
Variable **var_list_get_non_consts      (VarList *vlst, size_t *count);

bool is_operator  (char ch);
bool is_lparen    (char ch);
bool is_rparen    (char ch);
bool is_comma     (char ch);
bool is_equation  (char ch);
bool is_delimiter (char ch);
bool is_constant  (const String s);
bool is_function  (const String s);
bool is_variable  (const String s);

TokenType tokenize_find_type_str       (String s);
TokenType tokenize_delimiter_type_char (char ch);
bool      tokenize_string_to_tokentype (TokenList *lst, const String s);
bool      tokenize_type_to_data        (TokenList *lst, VarList *vlst);
bool      tokenize_process_equation    (TokenList *lst);

bool syntax_check_msg_basic(TokenList *lst);
bool syntax_check_msg_advanced(TokenList *lst);

bool infix_to_postfix          (TokenList *postfixLst, const TokenList *infixLst);
bool solver_process_op_or_func (const Token *op, TokenList *stack);
bool solver_solve              (const TokenList *postfixLst, const VarList *vlst, double *value);

String string_space_remove (const String orjBuffer);
void   clear_stdin         (void);
double get_double_input    (double min, double max, char *msgFormat, ...);
int    get_integer_input   (int min, int max, char *msgFormat, ...);
char  *get_string_input    (char *buffer, int maxLength, char *msgFormat, ...);

double operator_binary_plus  (double a, double b);
double operator_binary_minus (double a, double  b);
double operator_mul          (double a, double b);
double operator_div          (double a, double b);
double operator_unary_plus   (double a);
double operator_unary_minus  (double a);
double operator_exp          (double a, double b);

double cot (double arg);
double csc (double arg);
double sec (double arg);
double acot(double arg);
double acsc(double arg);
double asec(double arg);
double lg  (double base, double arg);
double cbrt(double arg);

bool is_same_sign(double a, double b);
bool get_mat_equation(TokenList *lst, VarList *vlst);
double next_root_bisection(double lower, double lowerVal, double upper, double upperVal);
double next_root_regula_falsi(double lower, double lowerVal, double upper, double upperVal);

bool method_closed(double *result, String methodName, double (*nextRoot)(double lower, double lowerVal, double upper, double upperVal));
bool method_newton_raphson(double *result);
bool method_matrix_inverse(Matrix *result);
bool method_cholesky(Matrix *result);
bool method_gauss_seidal(Vector *result);
bool method_numerical_derivative(double *forward, double *central, double *backward);
bool method_simson(double *result1Div3, double *result3Div8);
bool method_trapezoid(double *result);
bool method_gregory_interpolation(double *result);


/***************************************************************/
/*                       GLOBAL CONSTANTS                      */
/***************************************************************/

const OrderOfOperation ORDERS[] = {
	{PRECEDENCE_COMMA, ASSOC_LEFT_TO_RIGHT},           /* INDEX_OP_COMMA */
	{PRECEDENCE_BINARY_PLUS, ASSOC_LEFT_TO_RIGHT},     /* INDEX_OP_BINARY_PLUS */
	{PRECEDENCE_BINARY_MINUS, ASSOC_LEFT_TO_RIGHT},    /* INDEX_OP_BINARY_MINUS */
	{PRECEDENCE_MUL, ASSOC_LEFT_TO_RIGHT},             /* INDEX_OP_MUL */
	{PRECEDENCE_DIV, ASSOC_LEFT_TO_RIGHT},             /* INDEX_OP_DIV */
	{PRECEDENCE_UNARY_PLUS, ASSOC_RIGHT_TO_LEFT},      /* INDEX_OP_UNARY_PLUS */
	{PRECEDENCE_UNARY_MINUS, ASSOC_RIGHT_TO_LEFT},     /* INDEX_OP_UNARY_MINUS */
	{PRECEDENCE_EXP, ASSOC_RIGHT_TO_LEFT},             /* INDEX_OP_EXP */
	{PRECEDENCE_FUNCTION, ASSOC_RIGHT_TO_LEFT},        /* INDEX_OP_FUNC */
	{PRECEDENCE_PAREN, ASSOC_LEFT_TO_RIGHT},           /* INDEX_OP_PAREN */ /* this will not be used */
};

const struct
{
	unsigned operandCount: 8;
	double (*fp) ();
}OPERATORS[] = {
	{0, NULL},
	{2, operator_binary_plus},
	{2, operator_binary_minus},
	{2, operator_mul},
	{2, operator_div},
	{1, operator_unary_plus},
	{1, operator_unary_minus},
	{2, operator_exp},
	{0, NULL},
	{0, NULL}
};

const struct
{
	String s;
	unsigned paramCount: 8;
	double (*fp) ();
}FUNCTIONS[] = {
	{"sin", 1, sin},
	{"cos", 1, cos},
	{"tan", 1, tan},
	{"cot", 1, cot},
	{"csc", 1, csc},
	{"sec", 1, sec},
	{"arcsin", 1, asin},
	{"arccos", 1, acos},
	{"arctan", 1, atan},
	{"arccot", 1, acot},
	{"arccsc", 1, acsc},
	{"arcsec", 1, asec},
	{"log", 2, lg},
	{"ln", 1, log},
	{"sqrt", 1, sqrt},
	{"cbrt", 1, cbrt},
	{NULL, 0, NULL}
};

const String TOKEN_STRINGS[] = {
	"TOKEN_INVALID",
	"TOKEN_CONSTANT",
	"TOKEN_VARIABLE",
	"TOKEN_LPAREN",
	"TOKEN_RPAREN",
	"TOKEN_COMMA",
	"TOKEN_OPERATOR",
	"TOKEN_FUNCTION",
	"TOKEN_EQUAL"
};

const char CHAR_DELIMITERS[] = "+-*/^(),=";

const char CHAR_OPERATORS[] = "+-*/^";



/***************************************************************/
/*                     TOKENLIST FUNCTIONS                     */
/***************************************************************/

/* return NULL, if failed */
bool token_list_init(TokenList *lst)
{
	CHECK_PARAMETERS(lst == NULL, return false);
	
	memset(lst, 0, sizeof(TokenList));
	
	if(token_list_reserve(lst, MIN_CAPACITY) == false)
	{
		return false;
	}
	
	return true;
}

/* delete list */
bool token_list_deinit(TokenList *lst)
{
	size_t i = 0;
	
	CHECK_TOKENLIST_VALIDANCE(lst, return false);
	
	for(i = 0; i < lst->length; i++)
	{
		if(lst->tokens[i].s != NULL)
		{
			free(lst->tokens[i].s);
		}
	}
	
	if(lst->tokens != NULL)
	{
		free(lst->tokens);
	}
	
	memset(lst, 0, sizeof(TokenList));
	
	return true;
}

/* return true if lst is empty */
bool token_list_is_empty(TokenList *lst)
{
	CHECK_TOKENLIST_VALIDANCE(lst, return true);
	
	return lst->length == 0;
}

/* add new token to tail return false, if failed */
bool token_list_add(TokenList *lst, Token token)
{
	CHECK_TOKENLIST_VALIDANCE(lst, return false);
	
	if(lst->length >= lst->capacity)
	{
		if(token_list_reserve(lst, lst->capacity * 2) == false)
		{
			return false;
		}
	}
	lst->tokens[lst->length++] = token;
	
	return true;
}

/* add new token to given index */
bool token_list_insert(TokenList *lst, Token token, size_t index)
{
	size_t i = 0;
	
	CHECK_TOKENLIST_VALIDANCE(lst, return false);
	CHECK_PARAMETERS(index > lst->length, return false);
	
	if(lst->length >= lst->capacity)
	{
		if(token_list_reserve(lst, lst->capacity * 2) == false)
		{
			return false;
		}
	}
	
	for(i = lst->length; i > index; i--)
	{
		lst->tokens[i] = lst->tokens[i-1];
	}
	
	lst->tokens[index] = token;
	lst->length++;
	
	return true;
}

/* get last token from tokenlist */
bool token_list_get_last(TokenList *lst, Token *token)
{
	CHECK_PARAMETERS(token == NULL, return false);
	CHECK_TOKENLIST_VALIDANCE(lst, return false);
	
	if(lst->length == 0) /* list empty */
	{
		return false;
	}
	
	*token = lst->tokens[lst->length-1];
	
	return true;
}

/* remove token from given index */
bool token_list_remove_at(TokenList *lst, size_t index)
{
	CHECK_TOKENLIST_VALIDANCE(lst, return false);
	CHECK_PARAMETERS(lst->length <= index, return false);
	
	memmove(&lst->tokens[index], &lst->tokens[index+1], (lst->length - index - 1) * sizeof(Token));
	lst->length--;
	
	return true;
}

/* remove last token from tokenList */
bool token_list_remove_last(TokenList *lst)
{
	CHECK_TOKENLIST_VALIDANCE(lst, return false);
	
	return token_list_remove_at(lst, lst->length-1);
}

/* remove token from given pointer */
bool token_list_remove(TokenList *lst, Token *token)
{
	CHECK_TOKENLIST_VALIDANCE(lst, return false);
	CHECK_PARAMETERS(lst->tokens > token, return false);
	
	return token_list_remove_at(lst, token - lst->tokens);
}

/* return false, if failed */
bool token_list_reserve(TokenList *lst, size_t newCapacity)
{
	Token *temp = NULL;
	
	CHECK_TOKENLIST_VALIDANCE(lst, return false);
	
	newCapacity = MAX(newCapacity, MIN_CAPACITY);
	
	if(newCapacity <= lst->capacity)
	{
		return true;
	}
	
	if(lst->tokens == NULL)
	{
		temp = (Token*)malloc(newCapacity * sizeof(Token));
	}
	else
	{
		temp = (Token*)realloc(lst->tokens, newCapacity * sizeof(Token));
	}
	
	CHECK_ALLOCATION(temp, return false);
		
	memset(&temp[lst->capacity], 0, (newCapacity - lst->capacity) * sizeof(Token));
	lst->tokens = temp;
	lst->capacity = newCapacity;
	
	return true;
}

/* return false, if failed */
bool token_list_shrink_to_fit(TokenList *lst)
{
	CHECK_TOKENLIST_VALIDANCE(lst, return false);
	
	if(lst->tokens != NULL)
	{
		if(lst->length != 0)
		{
			Token *temp = (Token*)realloc(lst->tokens, lst->length * sizeof(Token));
			if(temp == NULL)
			{
				return false;
			}
			lst->tokens = temp;
			lst->capacity = lst->length;
		}
		else
		{
			free(lst->tokens);
			lst->capacity = 0;
			lst->tokens = NULL;
		}
	}
	return true;
}


/***************************************************************/
/*                VARIABLE AND VARLIST FUNCTIONS               */
/***************************************************************/

/* initialize Variable, return false if failed */
bool variable_init(Variable *var, String varName)
{
	Variable temp = {NULL, 0, NULL, 0.0, false};
	
	CHECK_PARAMETERS(var == NULL, return false);
	
	temp.name = varName;
	*var = temp;
	
	return true;
}

/* clear initialized Variable, return false if failed */
bool variable_deinit(Variable *var)
{
	CHECK_VARIABLE_VALIDANCE(var, return false);
	
	if(var->tokens != NULL)
	{
		free(var->tokens);
	}
	
	var->tokens = NULL;
	var->length = 0;
	
	return true;
}

/* add new token to variable, return false if failed */
bool variable_add_token(Variable *var, Token *token)
{
	Token **temp = NULL;
	
	CHECK_VARIABLE_VALIDANCE(var, return false);
	CHECK_PARAMETERS(token == NULL, return false);
	
	if(var->tokens == NULL)
	{
		temp = (Token**)malloc(sizeof(Token*));
	}
	else
	{
		temp = (Token**)realloc(var->tokens, (var->length+1) * sizeof(Token*));
	}
	
	CHECK_ALLOCATION(temp, return false);
	
	var->tokens = temp;
	var->length++;
	
	var->tokens[var->length-1] = token; /* copy pointer */
	
	return true;
}


/* Initialize variable list, return false if failed */
bool var_list_init(VarList *vlst)
{
	VarList temp = {NULL, 0};
	
	CHECK_PARAMETERS(vlst == NULL, return false);
	
	*vlst = temp;
	
	return true;
}

/* clear initialized variable list, return false if falied */
bool var_list_deinit(VarList *vlst)
{
	size_t i = 0;
	
	CHECK_VARLIST_VALIDANCE(vlst, return false);
	
	for(i = 0; i < vlst->length; i++)
	{
		variable_deinit(&vlst->var[i]);
	}
	
	if(vlst->var != NULL)
	{
		free(vlst->var);
	}
	
	vlst->var = NULL;
	vlst->length = 0;
	
	return true;
}

/* if not exist return NOT_EXIST, otherwise return index */
int var_list_get_index(VarList *vlst, String varName)
{
	size_t i = 0;
	
	CHECK_VARLIST_VALIDANCE(vlst, return false);
	CHECK_PARAMETERS(varName == NULL, return false);
	
	for(i = 0; i < vlst->length; i++)
	{
		if(!strcmp(vlst->var[i].name, varName))
		{
			return i;
		}
	}
	
	return NOT_EXIST;
}

/* add new variable to variable list, return false if failed */
bool var_list_add(VarList *vlst, Variable var)
{
	Variable *temp = NULL;
	
	CHECK_VARLIST_VALIDANCE(vlst, return false);
	CHECK_VARIABLE_VALIDANCE(&var, return false);
	
	if(var_list_get_index(vlst, var.name) != NOT_EXIST)
	{
		fprintf(stderr, "Variable %s already exist\n", var.name);
		return false;
	}
	
	if(vlst->var == NULL)
	{
		temp = (Variable*)malloc(sizeof(Variable));
	}
	else
	{
		temp = (Variable*)realloc(vlst->var, (vlst->length+1) * sizeof(Variable));
	}
	
	CHECK_ALLOCATION(temp, return false);
	
	vlst->var = temp;
	vlst->length++;
	
	vlst->var[vlst->length-1] = var;
	
	return true;
}

/* Add predefined variabled to VarList ('e' and 'pi') */
bool var_list_add_predefined_vars(VarList *vlst)
{
	size_t i = 0;
	const double PI = 4*atan(1.0);
	const double NATURAL_EXP = exp(1.0);
	
	Variable PREDEFINED_VARIABLES[] = {
		{NULL, 0, "e", 0.0, true},
		{NULL, 0, "pi", 0.0, true}
	};	
	PREDEFINED_VARIABLES[0].value = NATURAL_EXP;
	PREDEFINED_VARIABLES[1].value = PI;
	
	CHECK_VARLIST_VALIDANCE(vlst, return false);
	
	for(i = 0; i < sizeof(PREDEFINED_VARIABLES)/sizeof(Variable); i++)
	{
		if(var_list_get_index(vlst, PREDEFINED_VARIABLES[i].name) == NOT_EXIST)
		{
			var_list_add(vlst, PREDEFINED_VARIABLES[i]);
		}
	}
	
	return true;
}

/* get number of non-constant variables in VarList */
size_t var_list_non_const_count(VarList *vlst)
{
	size_t i = 0, count = 0;
	
	CHECK_VARLIST_VALIDANCE(vlst, return 0);
	
	for(i = 0; i < vlst->length; i++)
	{
		count += !vlst->var[i].isConstant; /* add 1, if not constant */
	}
	
	return count;
}

Variable *var_list_get_first_non_const(VarList *vlst)
{
	size_t i = 0;
	
	CHECK_VARLIST_VALIDANCE(vlst, return NULL);
	
	for(i = 0; i < vlst->length; i++)
	{
		if(vlst->var[i].isConstant == false)
		{
			return &vlst->var[i];
		}
	}
	
	return NULL;
}

Variable **var_list_get_non_consts(VarList *vlst, size_t *count)
{
	size_t i = 0, r = 0, lCount = 0;
	Variable **vars = NULL;
	
	CHECK_PARAMETERS(count == NULL, return NULL);
	CHECK_VARLIST_VALIDANCE(vlst, return NULL);
	
	lCount = var_list_non_const_count(vlst);
	
	vars = (Variable**)malloc(lCount * sizeof(Variable*));
	CHECK_ALLOCATION(vars, return NULL);
	
	for(i = 0; i < vlst->length && r < lCount; i++) /* r < lCount is useless in single-thread programing approach */
	{
		if(vlst->var[i].isConstant == false)
		{
			vars[r++] = &vlst->var[i];
		}
	}
	
	*count = lCount;
	
	return vars;
}


/***************************************************************/
/*                       VECTOR FUNCTIONS                      */
/***************************************************************/

bool vector_create(Vector *v, size_t n)
{
	Vector newVector = {0};
	
	CHECK_PARAMETERS(v == NULL, return false);
	
	newVector.data = (double*)calloc(n, sizeof(double));
	CHECK_ALLOCATION(newVector.data, return false);
	
	newVector.n = n;
	*v = newVector;
	
	return true;
}

bool vector_delete(Vector *v)
{
	CHECK_VECTOR_VALIDANCE(v, return false);
	
	if(v->data != NULL)
	{
		free(v->data);
	}
	
	v->n = 0;
	v->data = NULL;
	
	return true;
}

bool vector_print(Vector *v)
{
	size_t i = 0;
	const String HORIZONTAL_TABLE = "------------------------------------------------------";
	const size_t COLUMN_WIDTH = 11;
	
	CHECK_VECTOR_VALIDANCE(v, return false);
	if(v->n == 0)
	{
		return true;
	}
	
	printf("\n%.*s", 2, HORIZONTAL_TABLE);
	for(i = 2; i <= COLUMN_WIDTH; i++)
	{
		printf(" ");
	}
	printf("%.*s\n", 2, HORIZONTAL_TABLE);
	
	for(i = 0; i < v->n; i++)
	{
		printf("| ");
		printf("%*G ", COLUMN_WIDTH-1, v->data[i]);
		printf("|\n");
	}
	
	printf("%.*s", 2, HORIZONTAL_TABLE);
	for(i = 2; i <= COLUMN_WIDTH; i++)
	{
		printf(" ");
	}
	printf("%.*s\n", 2, HORIZONTAL_TABLE);
	
	return true;
}

/***************************************************************/
/*                       MATRIX FUNCTIONS                      */
/***************************************************************/

bool matrix_create(Matrix *mat, size_t row, size_t col)
{
	double **data = NULL;
	size_t i = 0;
	
	CHECK_PARAMETERS(mat == NULL || row == 0 || col == 0, return false);
	
	data = (double**)malloc(row * sizeof(double*));
	CHECK_ALLOCATION(data, return false);
	
	for(i = 0; i < row; i++)
	{
		data[i] = (double*)calloc(col, sizeof(double));
		CHECK_ALLOCATION(data[i], 
			{
				size_t j = i-1;
				for(j = i-1; (long)j >= 0; j--)
				{
					free(data[j]);
				}
				free(data);
				return false;
			}
		);
	}
	
	mat->data = data;
	mat->row = row;
	mat->col = col;
	
	return true;
}

bool matrix_identity_create(Matrix *mat, size_t N)
{
	size_t i = 0;
	
	if(matrix_create(mat, N, N) == false)
	{
		return false;
	}
	
	for(i = 0; i < N; i++)
	{
		mat->data[i][i] = 1.0;
	}
	
	return true;
}

/* return first row index from startRow (included). if all elements are 0, return NOT_EXIST  */
int matrix_find_pivot_row(Matrix *mat, size_t startRow, size_t col)
{
	size_t i = 0;
	size_t maxRow = 0;
	
	CHECK_PARAMETERS(mat == NULL || startRow >= mat->row || col >= mat->col, return NOT_EXIST);
	CHECK_MATRIX_VALIDANCE(mat, return NOT_EXIST);
	
	for(maxRow = startRow, i = startRow+1; i < mat->row; i++)
	{
		maxRow = (fabs(mat->data[i][col]) > fabs(mat->data[maxRow][col])) ? i : maxRow;
	}
	
	return (fabs(mat->data[maxRow][col]) < ZERO_THRESHOLD) ? NOT_EXIST : (int)maxRow;
}

bool matrix_mul_row(Matrix *mat, size_t row, double multiplier)
{
	size_t j = 0;
	
	CHECK_MATRIX_VALIDANCE(mat, return false);
	CHECK_PARAMETERS(row >= mat->row, return false);
	
	for(j = 0; j < mat->col; j++)
	{
		mat->data[row][j] *= multiplier;
	}
	
	return true;
}

bool matrix_subtract_row(Matrix *mat, size_t resultRow, size_t minuendRow, size_t subtrahendRow)
{
	size_t j = 0;
	
	CHECK_MATRIX_VALIDANCE(mat, return false);
	CHECK_PARAMETERS(resultRow >= mat->row || minuendRow >= mat->row || subtrahendRow >= mat->row, return false);
	
	for(j = 0; j < mat->col; j++)
	{
		mat->data[resultRow][j] = mat->data[minuendRow][j] - mat->data[subtrahendRow][j];
	}
	
	return true;
}

bool matrix_delete(Matrix *mat)
{
	size_t i = 0;
	
	CHECK_MATRIX_VALIDANCE(mat, return false);
	
	if(mat->data != NULL)
	{
		for(i = 0; i < mat->row; i++)
		{
			free(mat->data[i]);
		}
		free(mat->data);
	}
	
	mat->row = 0;
	mat->col = 0;
	mat->data = NULL;
	
	return true;
}

bool matrix_print(Matrix *mat)
{
	size_t i = 0, j = 0;
	const String HORIZONTAL_TABLE = "------------------------------------------------------";
	const size_t COLUMN_WIDTH = 11;
	
	CHECK_MATRIX_VALIDANCE(mat, return false);
	
	if(mat->row == 0 || mat->col == 0)
	{
		return true;
	}
	
	printf("\n%.*s", mat->col+1, HORIZONTAL_TABLE);
	for(j = 2*mat->col; j <= mat->col * COLUMN_WIDTH; j++)
	{
		printf(" ");
	}
	printf("%.*s\n", mat->col+1, HORIZONTAL_TABLE);
	
	for(i = 0; i < mat->row; i++)
	{
		printf("| ");
		for(j = 0; j < mat->col; j++)
		{
			printf("%*G ", COLUMN_WIDTH-1, mat->data[i][j]);
		}
		printf("|\n");
	}
	
	printf("%.*s", mat->col+1, HORIZONTAL_TABLE);
	for(j = 2*mat->col; j <= mat->col * COLUMN_WIDTH; j++)
	{
		printf(" ");
	}
	printf("%.*s\n", mat->col+1, HORIZONTAL_TABLE);
	
	return true;
}

bool matrix_print_transpose(Matrix *mat)
{
	size_t i = 0, j = 0;
	const String HORIZONTAL_TABLE = "------------------------------------------------------";
	const size_t COLUMN_WIDTH = 11;
	
	CHECK_MATRIX_VALIDANCE(mat, return false);
	
	if(mat->row == 0 || mat->col == 0)
	{
		return true;
	}
	
	printf("\n%.*s", mat->row+1, HORIZONTAL_TABLE);
	for(j = 2*mat->row; j <= mat->row * COLUMN_WIDTH; j++)
	{
		printf(" ");
	}
	printf("%.*s\n", mat->row+1, HORIZONTAL_TABLE);
	
	for(j = 0; j < mat->col; j++)
	{
		printf("| ");
		for(i = 0; i < mat->row; i++)
		{
			printf("%*G ", COLUMN_WIDTH-1, mat->data[i][j]);
		}
		printf("|\n");
	}
	
	printf("%.*s", mat->row+1, HORIZONTAL_TABLE);
	for(j = 2*mat->row; j <= mat->row * COLUMN_WIDTH; j++)
	{
		printf(" ");
	}
	printf("%.*s\n", mat->row+1, HORIZONTAL_TABLE);
	
	return true;
}

bool matrix_print_augmented(Matrix *mat1, Matrix *mat2)
{
	size_t i = 0, j = 0;
	size_t totalCols = 0;
	const String HORIZONTAL_TABLE = "------------------------------------------------------";
	const size_t COLUMN_WIDTH = 11;
	
	CHECK_MATRIX_VALIDANCE(mat1, return false);
	CHECK_MATRIX_VALIDANCE(mat2, return false);
	
	if(mat1->row != mat2->row)
	{
		return false;
	}
	
	if(mat1->col == 0)
	{
		return matrix_print(mat2);
	}
	else if(mat2->col == 0)
	{
		return matrix_print(mat1);
	}
	
	totalCols = mat1->col + mat2->col;
	
	printf("\n%.*s", totalCols+1, HORIZONTAL_TABLE);
	for(j = 2*totalCols-2; j <= totalCols * COLUMN_WIDTH; j++)
	{
		printf(" ");
	}
	printf("%.*s\n", totalCols+1, HORIZONTAL_TABLE);
	
	for(i = 0; i < mat1->row; i++)
	{
		printf("| ");
		for(j = 0; j < mat1->col; j++)
		{
			printf("%*G ", COLUMN_WIDTH-1, mat1->data[i][j]);
		}
		printf("| ");
		for(j = 0; j < mat2->col; j++)
		{
			printf("%*G ", COLUMN_WIDTH-1, mat2->data[i][j]);
		}
		printf("|\n");
	}
	
	printf("%.*s", totalCols+1, HORIZONTAL_TABLE);
	for(j = 2*totalCols-2; j <= totalCols * COLUMN_WIDTH; j++)
	{
		printf(" ");
	}
	printf("%.*s\n", totalCols+1, HORIZONTAL_TABLE);
	
	return true;
	
	
}

bool matrix_swap_rows(Matrix *mat, size_t r1, size_t r2)
{
	double *temp = NULL;
	
	CHECK_MATRIX_VALIDANCE(mat, return false);
	
	/* loopless swap */
	temp = mat->data[r1];
	mat->data[r1] = mat->data[r2];
	mat->data[r2] = temp;
	
	return true;
}

/***************************************************************/
/*                    INTERACTION FUNCFIONS                    */
/***************************************************************/

void menu_print(void)
{
	printf("\n%s", 
		"+----------------------------------+\n"
		"| 0- Exit                          |\n"
		"| 1- Bisection Method              |\n"
		"| 2- Resula-Falsi Method           |\n"
		"| 3- Newton-Raphson Method         |\n"
		"| 4- Inverse of a NxN Matrix       |\n"
		"| 5- Cholesky (ALU) Method         |\n"
		"| 6- Gauss Seidal                  |\n"
		"| 7- Numerical Derivative          |\n"
		"| 8- Simson Method                 |\n"
		"| 9- Trapezoid Method              |\n"
		"| 10- Gregory-Newton Interpolation |\n"
		"+----------------------------------+\n"
	);
}

Method get_method(void)
{
	int input = 0;
	
	input = get_integer_input(0, MAX_METHOD, "Enter operation: ");
	
	return (Method)(input-1);
}

String get_mat_function(void)
{
	String s = NULL;
	size_t length = 0;
	char buff[MAX_BUFFER];
	
	get_string_input(buff, MAX_BUFFER, "Enter mathematical function: ");
	
	length = strlen(buff);
	
	s = (String)malloc((length+1) * sizeof(char));
	CHECK_ALLOCATION(s, return NULL);
	
	memcpy(s, buff, (length+1)*sizeof(char));
	
	return s;
}


/***************************************************************/
/*                    TOKENIZATION FUNCFIONS                   */
/***************************************************************/

bool is_operator(char ch)
{
	int i = 0;
	
	for(i = 0; CHAR_OPERATORS[i] != '\0'; i++)
	{
		if(ch == CHAR_OPERATORS[i])
		{
			return true;
		}
	}
	return false;
}

bool is_lparen(char ch)
{
	return ch == CHAR_DELIMITERS[INDEX_CHAR_LPAREN];
}

bool is_rparen(char ch)
{
	return ch == CHAR_DELIMITERS[INDEX_CHAR_RPAREN];
}

bool is_comma(char ch)
{
	return ch == CHAR_DELIMITERS[INDEX_CHAR_COMMA];
}

bool is_equation(char ch)
{
	return ch == CHAR_DELIMITERS[INDEX_CHAR_EQUATION];
}

bool is_delimiter(char ch)
{
	int i = 0;
	
	for(i = 0; CHAR_DELIMITERS[i] != '\0'; i++)
	{
		if(ch == CHAR_DELIMITERS[i])
		{
			return true;
		}
	}
	return ch == '\0';
}

bool is_constant(const String s)
{
	bool dotFound = false;
	size_t i = 0;
	assert(s != NULL);
	for(i = 0; s[i] != '\0'; i++)
	{
		if(s[i] == '.')
		{
			if(dotFound == true || i == 0) /* there are 2 ore more dot, or dot found in first place (before any digit) */
			{
				return false;
			}
			dotFound = true;
		}
		else if(!isdigit(s[i]))
		{
			return false;
		}
	}
	return true;
}

bool is_function(const String s)
{
	size_t i = 0;
	assert(s != NULL);
	for(i = 0; FUNCTIONS[i].s != NULL; i++)
	{
		if(!strcmp(s, FUNCTIONS[i].s))
		{
			return true;
		}
	}
	return false;
}

bool is_variable(const String s)
{
	size_t i = 0;
	
	CHECK_PARAMETERS(s == NULL, return false);
	
	if(!isalpha(s[0]) && s[0] != '_')
	{
		return false;
	}
	
	for(i = 1; s[i] != '\0'; i++)
	{
		if(!isalnum(s[i]) && s[i] != '_')
		{
			return false;
		}
	}
	return true;
}


/* return type of given string */
TokenType tokenize_find_type_str(const String s)
{
	size_t length = 0;
	
	CHECK_PARAMETERS(s == NULL, return TOKEN_INVALID);
	
	length = strlen(s);
	
	if(length == 1)
	{
		TokenType type = tokenize_delimiter_type_char(*s);
		if(type != TOKEN_INVALID)
		{
			return type;
		}
	}
	if(is_constant(s))
	{
		return TOKEN_CONSTANT;
	}
	else if(is_function(s))
	{
		return TOKEN_FUNCTION;
	}
	else if(is_variable(s))
	{
		return TOKEN_VARIABLE;
	}
	return TOKEN_INVALID;
}

/* return type of given delimiter character */
TokenType tokenize_delimiter_type_char(char ch)
{
	if(is_operator(ch))
	{
		return TOKEN_OPERATOR;
	}
	else if(is_lparen(ch))
	{
		return TOKEN_LPAREN;
	}
	else if(is_rparen(ch))
	{
		return TOKEN_RPAREN;
	}
	else if(is_comma(ch))
	{
		return TOKEN_COMMA;
	}
	else if(is_equation(ch))
	{
		return TOKEN_EQUAL;
	}
	return TOKEN_INVALID;
}

/* tokenize spaceless string to given TokenList */
bool tokenize_string_to_tokentype(TokenList *lst, const String s)
{
	int i = 0, j = 1;
	
	CHECK_PARAMETERS(lst == NULL, return false);
	CHECK_PARAMETERS(s == NULL, return false);
	
	token_list_init(lst);
	if(lst == NULL)
	{
		return false;
	}
	
	i = 0;
	while(s[i] != '\0')
	{
		Token token = {0};
		j = i;
		
		while(!is_delimiter(s[j]))
		{
			j++;
		}
		
		if(i != j)
		{
			int length = j-i;
			
			token.s = (String)malloc((size_t)(length+1) * sizeof(char));
			CHECK_ALLOCATION(token.s, return false);
			
			memcpy(token.s, &s[i], length);
			token.s[length] = '\0';
			
			token.type = tokenize_find_type_str(token.s);
			
			token_list_add(lst, token);
		}
		
		/* adding delimiter to list */
		if((token.type = tokenize_delimiter_type_char(s[j])) != TOKEN_INVALID)
		{
			char *buff = malloc(2 * sizeof(char));
			CHECK_ALLOCATION(buff, return false);
			
			buff[0] = s[j];
			buff[1] = '\0';
			
			token.s = buff;
			token_list_add(lst, token);
			
			i = j+1;
		}
		else
		{
			printf("%c\n", s[j]);
			i = j; /* end of string */
		}	
	}
	
	return token_list_shrink_to_fit(lst);
}

/* set token's type properities. */
bool tokenize_type_to_data(TokenList *lst, VarList *vlst)
{
	size_t i = 0;
	bool isValid = true;
	
	CHECK_PARAMETERS(vlst == NULL, return false);
	CHECK_TOKENLIST_VALIDANCE(lst, return false);
	
	var_list_init(vlst);
	var_list_add_predefined_vars(vlst);
	
	for(i = 0; i < lst->length; i++)
	{
		Token *t = &lst->tokens[i];
		switch(t->type)
		{
			case TOKEN_CONSTANT:{
				char *ptr = NULL;
				double value = strtod(t->s, &ptr);
				if(ptr == t->s) /* error occured */
				{
					fprintf(stderr, "\'%s\' can not convert to double number\n", t->s);
					isValid = false;
				}
				t->data.val = value;
			}break;
			
			case TOKEN_LPAREN:
			case TOKEN_RPAREN:{
				t->data.order = ORDERS[INDEX_OP_PAREN];
			}break;
			
			case TOKEN_COMMA:{
				t->data.order = ORDERS[INDEX_OP_COMMA];
			}break;
			
			case TOKEN_OPERATOR:{
				if(*t->s == CHAR_DELIMITERS[INDEX_CHAR_PLUS])
				{
					if(i == 0 || lst->tokens[i-1].type == TOKEN_LPAREN || lst->tokens[i-1].type == TOKEN_OPERATOR) /* unary */
					{
						t->data.paramCount = OPERATORS[INDEX_OP_UNARY_PLUS].operandCount;
						t->data.fp = OPERATORS[INDEX_OP_UNARY_PLUS].fp;
						t->data.order = ORDERS[INDEX_OP_UNARY_PLUS];
					}
					else /* binary */
					{
						t->data.paramCount = OPERATORS[INDEX_OP_BINARY_PLUS].operandCount;
						t->data.fp = OPERATORS[INDEX_OP_BINARY_PLUS].fp;
						t->data.order = ORDERS[INDEX_OP_BINARY_PLUS];
					}
				}
				else if(*t->s == CHAR_DELIMITERS[INDEX_CHAR_MINUS])
				{
					if(i == 0 || lst->tokens[i-1].type == TOKEN_LPAREN || lst->tokens[i-1].type == TOKEN_OPERATOR) /* unary */
					{
						t->data.paramCount = OPERATORS[INDEX_OP_UNARY_MINUS].operandCount;
						t->data.fp = OPERATORS[INDEX_OP_UNARY_MINUS].fp;
						t->data.order = ORDERS[INDEX_OP_UNARY_MINUS];
					}
					else /* binary */
					{
						t->data.paramCount = OPERATORS[INDEX_OP_BINARY_MINUS].operandCount;
						t->data.fp = OPERATORS[INDEX_OP_BINARY_MINUS].fp;
						t->data.order = ORDERS[INDEX_OP_BINARY_MINUS];
					}
				}
				else if(*t->s == CHAR_DELIMITERS[INDEX_CHAR_MUL])
				{
					t->data.paramCount = OPERATORS[INDEX_OP_MUL].operandCount;
					t->data.fp = OPERATORS[INDEX_OP_MUL].fp;
					t->data.order = ORDERS[INDEX_OP_MUL];
				}
				else if(*t->s == CHAR_DELIMITERS[INDEX_CHAR_DIV])
				{
					t->data.paramCount = OPERATORS[INDEX_OP_DIV].operandCount;
					t->data.fp = OPERATORS[INDEX_OP_DIV].fp;
					t->data.order = ORDERS[INDEX_OP_DIV];
				}
				else if(*t->s == CHAR_DELIMITERS[INDEX_CHAR_EXP])
				{
					t->data.paramCount = OPERATORS[INDEX_OP_EXP].operandCount;
					t->data.fp = OPERATORS[INDEX_OP_EXP].fp;
					t->data.order = ORDERS[INDEX_OP_EXP];
				}
				else
				{
					fprintf(stderr, "Operator \'%s\' not found\n", t->s);
					isValid = false;
				}
			}break;
			
			case TOKEN_FUNCTION:{
				size_t i = 0;
				
				t->data.order = ORDERS[INDEX_OP_FUNC];
				
				for(i = 0, t->data.fp = NULL; FUNCTIONS[i].s != NULL && t->data.fp == NULL; i++)
				{
					if(!strcmp(t->s, FUNCTIONS[i].s))
					{
						t->data.paramCount = FUNCTIONS[i].paramCount;
						t->data.fp = FUNCTIONS[i].fp;
					}
				}
				
				if(t->data.fp == NULL) /* not found */
				{
					fprintf(stderr, "Function \'%s\' not found\n", t->s);
					isValid = false;
				}
			}break;
			
			case TOKEN_VARIABLE:{
				int index = var_list_get_index(vlst, t->s);
				if(index != NOT_EXIST)
				{
					Variable *var = &vlst->var[index];
					variable_add_token(var, t);
					t->data.varIndex = index;
				}
				else
				{
					Variable var = {0};
					variable_init(&var, t->s);
					variable_add_token(&var, t);
					var_list_add(vlst, var);
					t->data.varIndex = vlst->length-1;
				}
				
			}break;
			
			default:
			break;
		}
	}
	return isValid;
}

/* convert '=' token to -(rvalue) tokens */
bool tokenize_process_equation(TokenList *lst)
{
	size_t i = 0;
	bool equationFound = false;
	
	CHECK_TOKENLIST_VALIDANCE(lst, return false);
	
	for(i = 0; i < lst->length && equationFound == false; i++)
	{
		if(lst->tokens[i].type == TOKEN_EQUAL)
		{
			Token binaryMinus = {0};
			Token lParen = {0};
			Token rParen = {0};
			
			binaryMinus.s = (String)malloc(2 * sizeof(char));
			CHECK_ALLOCATION(binaryMinus.s, return false);
			lParen.s = (String)malloc(2 * sizeof(char));
			CHECK_ALLOCATION(lParen.s, return false);
			rParen.s = (String)malloc(2 * sizeof(char));
			CHECK_ALLOCATION(rParen.s, return false);
			
			
			binaryMinus.type = TOKEN_OPERATOR, binaryMinus.data.order = ORDERS[INDEX_OP_BINARY_MINUS], strcpy(binaryMinus.s, "-");
			lParen.type = TOKEN_LPAREN, lParen.data.order = ORDERS[INDEX_OP_PAREN], strcpy(lParen.s, "(");
			rParen.type = TOKEN_RPAREN, rParen.data.order = ORDERS[INDEX_OP_PAREN], strcpy(rParen.s, ")");
			
			equationFound = true;
			
			token_list_remove_at(lst, i); /* remove '=' */
			token_list_insert(lst, binaryMinus, i);
			token_list_insert(lst, lParen, i+1);
			token_list_add(lst, rParen);
		}
	}
	
	return true;
}


/***************************************************************/
/*                        SYNTAX CONTROL                       */
/***************************************************************/

/* make basic syntax check, return true if valid, after tokenize input string */
bool syntax_check_msg_basic(TokenList *lst)
{
	size_t i = 0;
	int parenCount = 0;
	int equationCount = 0;	
	bool isValid = true;
	
	CHECK_TOKENLIST_VALIDANCE(lst, return false);
	
	for(i = 0; i < lst->length; i++)
	{
		if(parenCount < 0)
		{
			fprintf(stderr, "No \'(\' for \')\'\n");
			isValid = false;
		}
		
		switch(lst->tokens[i].type)
		{
			case TOKEN_INVALID:
				fprintf(stderr, "Syntax error: \"%s\"\n", lst->tokens[i].s);
				isValid = false;
			break;
			
			case TOKEN_LPAREN:
				parenCount++;
			break;
			
			case TOKEN_RPAREN:
				parenCount--;
			break;
			
			case TOKEN_EQUAL:
				equationCount++;
			break;
			
			default:
			break;
		}
	}
	
	if(parenCount > 0)
	{
		isValid = false;
		fprintf(stderr, "Some parenthesis not closed\n");
	}
	else if(parenCount < 0)
	{
		isValid = false;
		fprintf(stderr, "Too many close paranthesis\n");
	}
	
	if(equationCount > 1)
	{
		isValid = false;
		fprintf(stderr, "More than one equation\n");
	}
	
	return isValid;
}

/* make advanced sytanx check after basic syntax check and deequation, before postfixing */
bool syntax_check_msg_advanced(TokenList *lst)
{
	size_t i = 0;
	bool isValid = true;
	
	CHECK_TOKENLIST_VALIDANCE(lst, return false);
	
	for(i = 0; i < lst->length; i++)
	{
		Token *prev = NULL, *next = NULL, *t = &lst->tokens[i];
		bool nextValid = true, prevValid = true;
		
		if(i != 0)
		{
			prev = &lst->tokens[i-1];
		}
		if(i != lst->length-1)
		{
			next = &lst->tokens[i+1];
		}
		
		switch(t->type)
		{
			case TOKEN_LPAREN:{
				if(prev != NULL)
				{
					if(	prev->type != TOKEN_OPERATOR &&
						prev->type != TOKEN_FUNCTION &&
						prev->type != TOKEN_LPAREN &&
						prev->type != TOKEN_COMMA
					)
					{
						prevValid = false;
					}
				}
				if(next != NULL)
				{
					if(	next->type != TOKEN_OPERATOR &&
						next->type != TOKEN_FUNCTION &&
						next->type != TOKEN_LPAREN &&
						next->type != TOKEN_RPAREN &&
						next->type != TOKEN_CONSTANT &&
						next->type != TOKEN_VARIABLE						
					)
					{
						nextValid = false;
					}
				}
			}break;
			
			case TOKEN_RPAREN:{
				if(prev != NULL)
				{
					if(	prev->type != TOKEN_CONSTANT &&
						prev->type != TOKEN_RPAREN &&
						prev->type != TOKEN_VARIABLE &&
						prev->type != TOKEN_LPAREN /* TODO: look here */
					)
					{
						prevValid = false;
					}
				}
				if(next != NULL)
				{
					if(	next->type != TOKEN_OPERATOR &&
						next->type != TOKEN_RPAREN						
					)
					{
						nextValid = false;
					}
				}
			}break;
			
			case TOKEN_COMMA:{
				if(prev != NULL)
				{
					if(	prev->type != TOKEN_CONSTANT &&
						prev->type != TOKEN_VARIABLE &&
						prev->type != TOKEN_FUNCTION &&
						prev->type != TOKEN_RPAREN
					)
					{
						prevValid = false;
					}
				}
				if(next != NULL)
				{
					if(	next->type != TOKEN_LPAREN &&
						next->type != TOKEN_OPERATOR &&
						next->type != TOKEN_VARIABLE &&
						next->type != TOKEN_FUNCTION &&
						next->type != TOKEN_CONSTANT					
					)
					{
						nextValid = false;
					}
				}
			}break;
			
			case TOKEN_OPERATOR:{
				if(t->data.fp == operator_unary_minus || t->data.fp == operator_unary_plus)
				{
					if(prev != NULL)
					{
						if(	prev->type != TOKEN_LPAREN &&
							prev->type != TOKEN_COMMA &&
							prev->type != TOKEN_OPERATOR
						)
						{
							prevValid = false;
						}
					}
					if(next != NULL)
					{
						if(	next->type != TOKEN_CONSTANT &&
							next->type != TOKEN_FUNCTION &&
							next->type != TOKEN_VARIABLE &&
							next->type != TOKEN_LPAREN			
						)
						{
							nextValid = false;
						}
					}					
				}
				else /* binary */
				{
					if(prev != NULL)
					{
						if(	prev->type != TOKEN_FUNCTION &&
							prev->type != TOKEN_CONSTANT &&
							prev->type != TOKEN_VARIABLE &&
							prev->type != TOKEN_RPAREN
						)
						{
							prevValid = false;
						}
					}
					if(next != NULL)
					{
						if(	next->type != TOKEN_LPAREN &&
							next->type != TOKEN_FUNCTION &&
							next->type != TOKEN_CONSTANT &&
							next->type != TOKEN_VARIABLE &&
							next->type != TOKEN_OPERATOR				
						)
						{
							nextValid = false;
						}
					}
				}
				
				if(prev != NULL && next != NULL)
				{
					if(prev->type == TOKEN_OPERATOR && next->type == TOKEN_OPERATOR)
					{
						fprintf(stderr, "Invalid operator sequence: \'%s\' \'%s\' \'%s\'",
							prev->s, t->s, next->s);
						isValid = false;
					}
				}
				
			}break;
			
			case TOKEN_FUNCTION:{
				if(prev != NULL)
				{
					if(	prev->type != TOKEN_OPERATOR &&
						prev->type != TOKEN_LPAREN &&
						prev->type != TOKEN_COMMA
					)
					{
						prevValid = false;
					}
				}
				if(next != NULL)
				{
					if(next->type != TOKEN_LPAREN)
					{
						nextValid = false;
					}
				}
			}break;
			
			case TOKEN_VARIABLE:
			case TOKEN_CONSTANT:{
				if(prev != NULL)
				{
					if(	prev->type != TOKEN_OPERATOR &&
						prev->type != TOKEN_LPAREN &&
						prev->type != TOKEN_COMMA
					)
					{
						prevValid = false;
					}
				}
				if(next != NULL)
				{
					if(	next->type != TOKEN_COMMA &&
						next->type != TOKEN_OPERATOR &&
						next->type != TOKEN_RPAREN				
					)
					{
						nextValid = false;
					}
				}
			}break;
			
			default:
			break;
			
		}
		
		if(prevValid == false)
		{
			isValid = false;
			fprintf(stderr, "Incompatible token \'%s\' before a \'%s\'\n", prev->s, t->s);
		}
		if(nextValid == false)
		{
			isValid = false;
			fprintf(stderr, "Incompatible token \'%s\' after a \'%s\'\n", next->s, t->s);
		}
	}
	return isValid;
}

/***************************************************************/
/*                   SHUNTING YARD ALGORITHM                   */
/***************************************************************/

/* create postfix of given infix expression using shunting yard algorithm, return false if failed */
bool infix_to_postfix(TokenList *postfixLst, const TokenList *infixLst)
{
	size_t i = 0;
	TokenList newLst = {0};
	TokenList operatorStack = {0};
	
	CHECK_TOKENLIST_VALIDANCE(infixLst, return false);
	CHECK_PARAMETERS(postfixLst == NULL, return false);
	
	token_list_init(postfixLst);
	
	token_list_init(&newLst);
	token_list_init(&operatorStack);
	
	CHECK_ALLOCATION(newLst.tokens, return false);
	CHECK_ALLOCATION(operatorStack.tokens, return false);
	
	for(i = 0; i < infixLst->length; i++)
	{
		Token *t = &infixLst->tokens[i];
		switch(t->type)
		{
			case TOKEN_CONSTANT:
			case TOKEN_VARIABLE:{
				token_list_add(&newLst, *t);
			}break;
			
			case TOKEN_FUNCTION:{
				token_list_add(&operatorStack, *t);
			}break;
			
			case TOKEN_OPERATOR:{
				Token last = {0};
				bool isContinue = false;
				
				do
				{
					isContinue = !token_list_is_empty(&operatorStack);
					if(isContinue)
					{
						token_list_get_last(&operatorStack, &last);
						if(last.type != TOKEN_LPAREN && 
							(last.data.order.precedence > t->data.order.precedence || 
							(last.data.order.precedence == t->data.order.precedence && t->data.order.associativity == ASSOC_LEFT_TO_RIGHT)))
						{
							token_list_add(&newLst, last);
							token_list_remove_last(&operatorStack);
						}
						else
						{
							isContinue = false;
						}
					}
				}while(isContinue);
				
				token_list_add(&operatorStack, *t);
				
			}break;
			
			case TOKEN_COMMA:{
				Token last = {0};
				bool isContinue = false;
				
				do
				{
					isContinue = !token_list_is_empty(&operatorStack);
					if(isContinue)
					{
						token_list_get_last(&operatorStack, &last);
						if(last.type != TOKEN_LPAREN)
						{
							token_list_add(&newLst, last);
							token_list_remove_last(&operatorStack);
						}
						else
						{
							isContinue = false;
						}
					}
				}while(isContinue);
				
			}break;
			
			case TOKEN_LPAREN:{
				token_list_add(&operatorStack, *t);
			}break;
			
			case TOKEN_RPAREN:{
				Token last = {0};
				bool isContinue = false;
				
				do
				{
					isContinue = !token_list_is_empty(&operatorStack);
					if(isContinue)
					{
						token_list_get_last(&operatorStack, &last);
						if(last.type != TOKEN_LPAREN)
						{
							token_list_add(&newLst, last);
							token_list_remove_last(&operatorStack);
						}
						else
						{
							token_list_remove_last(&operatorStack);
							if(!token_list_is_empty(&operatorStack))
							{
								token_list_get_last(&operatorStack, &last);
								if(last.type == TOKEN_FUNCTION)
								{
									token_list_add(&newLst, last);
									token_list_remove_last(&operatorStack);
								}
							}
							isContinue = false;
						}
					}
				}while(isContinue);
				
				if(!token_list_is_empty(&operatorStack))
				{
					token_list_get_last(&operatorStack, &last);
					
					if(last.type == TOKEN_FUNCTION)
					{
						token_list_add(&newLst, last);
						token_list_remove_last(&operatorStack);
					}
				}
				
			}break;
			
			default:
				assert(!"This is not normal");
			break;
		}
	}
	
	while(!token_list_is_empty(&operatorStack))
	{
		Token last;
		token_list_get_last(&operatorStack, &last);
		
		token_list_add(&newLst, last);
		token_list_remove_last(&operatorStack);
	}
	
	*postfixLst = newLst;
	
	return true;
}

/* solve given operator using given stack, return false if failed */
bool solver_process_op_or_func(const Token *op, TokenList *stack)
{
	bool isValid = true;
	
	CHECK_PARAMETERS(op == NULL, return false);
	CHECK_TOKENLIST_VALIDANCE(stack, return false);
	
	if(stack->length < op->data.paramCount)
	{
		isValid = false;
	}
	else
	{
		Token resultToken = {0};
		resultToken.type = TOKEN_CONSTANT;
		
		switch(op->data.paramCount)
		{
			
			case 1:{
				Token o;
				
				token_list_get_last(stack, &o);
				token_list_remove_last(stack);
				
				resultToken.data.val = op->data.fp(o.data.val);
			}break;
			
			case 2:{
				
				Token o1, o2;
				
				token_list_get_last(stack, &o2);
				token_list_remove_last(stack);
				token_list_get_last(stack, &o1);
				token_list_remove_last(stack);
				
				resultToken.data.val = op->data.fp(o1.data.val, o2.data.val);
			}break;
			
			default:
				assert(!"Not implemented\n");
			break;
		}
		
		token_list_add(stack, resultToken);
	}
	
	if(isValid == false)
	{
		fprintf(stderr, "Operator \'%s\' missing operator\n", op->s);
	}
	
	return isValid;
}

/* solve mathematical expression given postfix list and variable list, return false if failed */
bool solver_solve(const TokenList *postfixLst, const VarList *vlst, double *value)
{
	size_t i = 0;
	TokenList tokenStack;
	Token tempToken;
	
	CHECK_PARAMETERS(value == NULL, return false);
	CHECK_TOKENLIST_VALIDANCE(postfixLst, return false);
	CHECK_VARLIST_VALIDANCE(vlst, return false);
	
	token_list_init(&tokenStack);
	
	for(i = 0 ; i < postfixLst->length; i++)
	{
		Token *t = &postfixLst->tokens[i];
		
		switch(t->type)
		{
			case TOKEN_VARIABLE:{
				t->data.val = vlst->var[t->data.varIndex].value;
			}
			/* fall through */
			case TOKEN_CONSTANT:{
				token_list_add(&tokenStack, *t);
			}break;
			
			case TOKEN_FUNCTION:
			case TOKEN_OPERATOR:{
				if(solver_process_op_or_func(t, &tokenStack) == false)
				{
					return false;
				}
			}break;
			
			default:
				assert(!"This is not normal");
			break;
		}
	}
	
	if(token_list_get_last(&tokenStack, &tempToken) != false)
	{
		*value = tempToken.data.val;
	}
	else
	{
		assert(!"Stack underflow\n");
	}
	
	return true;
}

/***************************************************************/
/*                             MAIN                            */
/***************************************************************/

int main(void)
{
	Method method = METHOD_EXIT;
		
	menu_print();
	
	do
	{
		method = get_method();
		
		switch(method)
		{
			case METHOD_BISECTION:{
				double result = 0.0;
				if(method_closed(&result, "bisection", next_root_bisection))
				{
					printf("\nResult: %lf\n", result);
				}
			}break;
			
			case METHOD_REGULA_FALSI:{
				double result = 0.0;
				if(method_closed(&result, "regula-falsi", next_root_regula_falsi))
				{
					printf("\nResult: %lf\n", result);
				}
			}break;
			
			case METHOD_NEWTON_RAPHSON:{
				double result = 0.0;
				if(method_newton_raphson(&result))
				{
					printf("\nResult: %lf\n", result);
				}
			}break;
			
			case METHOD_MATRIX_INVERSE:{
				Matrix result = {0};
				if(method_matrix_inverse(&result))
				{
					printf("\nResult:\n");
					matrix_print(&result);
					matrix_delete(&result);
				}
			}break;
			
			case METHOD_CHOLESKY:{
				Matrix result = {0};
				if(method_cholesky(&result))
				{
					printf("\nL Matrix:\n");
					matrix_print(&result);
					printf("\nU Matrix: \n");
					matrix_print_transpose(&result);
					matrix_delete(&result);
				}
			}break;
			
			case METHOD_GAUSS_SEIDAL:{
				Vector result = {0};
				if(method_gauss_seidal(&result))
				{
					printf("\nResult:\n");
					vector_print(&result);
					vector_delete(&result);
				}
			}break;
			
			case METHOD_NUMERICAL_derivative:{
				double forward = 0.0, central = 0.0, backward = 0.0;
				if(method_numerical_derivative(&forward, &central, &backward))
				{
					printf("\n\n|  Forward  |  Central  |  Backward |\n"
							   "|-----------|-----------|-----------|\n"
							   "|%11.5lf|%11.5lf|%11.5lf|\n", forward, central, backward);
				}
			}break;
			
			case METHOD_SIMPSON:{
				double result1Div3 = 0.0, result3Div8 = 0.0;
				if(method_simson(&result1Div3, &result3Div8))
				{
					printf("\nResult h/3: %lf\nResult 3h/8: %lf\n", result1Div3, result3Div8);
				}
			}break;
			
			case METHOD_TRAPEZOID:{
				double result = 0.0;
				if(method_trapezoid(&result))
				{
					printf("\nResult: %lf\n", result);
				}
			}break;
			
			case METHOD_GREGORY_INTERPOLATION:{
				double result = 0.0;
				if(method_gregory_interpolation(&result))
				{
					printf("\nResult: %lf\n", result);
				}
			}break;
			
			default:
			break;
		}
		
		#if (VERBOSE_LEVEL >= 1)
		menu_print();
		#endif
		
	}while(method != METHOD_EXIT);
	
	return 0;
}


/***************************************************************/
/*                 INPUT AND STRING FUNCFIONS                  */
/***************************************************************/

/* create (with malloc) new string without whitespaces, call free after use that */
String string_space_remove(const String orjBuffer)
{
	size_t i = 0, orjLength = strlen(orjBuffer), newLength = 0;
	String newBuffer = (String)malloc((orjLength+1) * sizeof(char));
	String tempBuffer = NULL;
	
	CHECK_ALLOCATION(newBuffer, return NULL);
	
	for(i = 0; i <= orjLength; i++)
	{
		if(!isspace(orjBuffer[i]))
		{
			newBuffer[newLength++] = orjBuffer[i];
		}
	}
	
	tempBuffer = (String)realloc(newBuffer, newLength * sizeof(char));
	if(tempBuffer == NULL)
	{
		return newBuffer;
	}
	return tempBuffer;
}

/* clear stdin after using scanf or getchar */
void clear_stdin(void)
{
	int ch = 0;
	while((ch = getchar()) != '\n' && ch != EOF);
}

/* Get double (decimal) from stdin, both min and max included */
double get_double_input(double min, double max, char *msgFormat, ...)
{
	bool isValid = true;
	double input = 0;
	va_list arg = NULL;
	
	CHECK_PARAMETERS(min > max, return 0);
	
	va_start(arg, msgFormat);
	
	do
	{
		isValid = true;
		
		if(msgFormat != NULL)
		{
			vprintf(msgFormat, arg);
		}
		
		if(scanf("%lf", &input) != 1)
		{
			fprintf(stderr, "Enter an decimal value\n");
			clear_stdin();
			isValid = false;
		}
		else if(input < min || input > max)
		{
			fprintf(stderr, "Value must be between %lf and %lf (both included)\n", min, max);
			clear_stdin();
			isValid = false;
		}		
	}while(isValid == false);
	
	va_end(arg);
	clear_stdin();

	return input;
}

/* Get integer from stdin, both min and max included */
int get_integer_input(int min, int max, char *msgFormat, ...)
{
	bool isValid = true;
	int input = 0;
	va_list arg = NULL;
	
	CHECK_PARAMETERS(min > max, return 0);
	
	va_start(arg, msgFormat);
	
	do
	{
		isValid = true;
		
		if(msgFormat != NULL)
		{
			vprintf(msgFormat, arg);
		}
		
		if(scanf("%d", &input) != 1)
		{
			fprintf(stderr, "Enter an integer value\n");
			clear_stdin();
			isValid = false;
		}
		else if(input < min || input > max)
		{
			fprintf(stderr, "Value must be between %d and %d (both included)\n", min, max);
			clear_stdin();
			isValid = false;
		}		
	}while(isValid == false);
	
	va_end(arg);
	clear_stdin();

	return input;
}

/* Get size from stdin, both min and max included */
size_t get_size_input(size_t min, size_t max, char *msgFormat, ...)
{
	bool isValid = true;
	unsigned long input = 0;
	va_list arg = NULL;
	
	CHECK_PARAMETERS(min > max, return 0);
	
	va_start(arg, msgFormat);
	
	do
	{
		isValid = true;
		
		if(msgFormat != NULL)
		{
			vprintf(msgFormat, arg);
		}
		
		if(scanf("%lu", &input) != 1)
		{
			fprintf(stderr, "Enter an integer value\n");
			clear_stdin();
			isValid = false;
		}
		else if(input < min || input > max)
		{
			fprintf(stderr, "Value must be between %lu and %lu (both included)\n", min, max);
			clear_stdin();
			isValid = false;
		}		
	}while(isValid == false);
	
	va_end(arg);
	clear_stdin();

	return (size_t)input;
}

/* Get string fom stdin, '\0' character included maxLength (example: maxLength = 5 mean, 4 char + '\0') */
char *get_string_input(char *buffer, int maxLength, char *msgFormat, ...)
{
	int ch = 0, i = 0;
	va_list arg = NULL;
	
	CHECK_PARAMETERS(buffer == NULL || maxLength == 0, return NULL);
	
	if(msgFormat != NULL)
	{
		va_start(arg, msgFormat);
		vprintf(msgFormat, arg);
		va_end(arg);
	}
	
	while((ch = getchar()) != '\n' && ch != EOF)
	{
		if(i < maxLength-1)
		{
			buffer[i++] = (char)ch;
		}
	}
	buffer[i] = '\0';
	
	return buffer;
}

/* if not square get row and column size, if square get size. return false if failed */
bool get_matrix_size_input(size_t *row, size_t *col, bool isSquare)
{
	if(isSquare)
	{
		size_t sizeInput = 0;
		
		CHECK_PARAMETERS(row == NULL && col == NULL, return false);
		
		sizeInput = get_size_input(0, UINT_MAX, "Enter matrix size: ");
		
		if(row != NULL)
		{
			*row = sizeInput;
		}
		if(col != NULL)
		{
			*col = sizeInput;
		}
	}
	else
	{
		size_t rowInput = 0, colInput = 0;
		
		CHECK_PARAMETERS(row == NULL || col == NULL, return false);
		
		rowInput = get_size_input(0, UINT_MAX, "Enter row size: ");
		colInput = get_size_input(0, UINT_MAX, "Enter col size: ");
		
		*row = rowInput;
		*col = colInput;
	}
	
	return true;
}

/* get matrix data from user, return false if failed */
bool get_matrix_input(Matrix *mat, char *msgFormat, ...)
{
	size_t i = 0, j = 0;
	va_list arg = NULL;
	
	CHECK_MATRIX_VALIDANCE(mat, return false);
	CHECK_PARAMETERS(mat->data == NULL, return false);
	
	va_start(arg, msgFormat);
	
	if(msgFormat != NULL)
	{
		vprintf(msgFormat, arg);
	}
	
	va_end(arg);
	
	for(i = 0; i < mat->row; i++)
	{
		for(j = 0; j < mat->col; j++)
		{
			mat->data[i][j] = get_double_input(-HUGE_VAL, HUGE_VAL, "matrix[%lu][%lu] = ", (unsigned long)i, (unsigned long)j);
		}
	}
	
	return true;
}

bool get_vector_input(Vector *v, char *vectorName, char *msgFormat, ...)
{
	size_t i = 0;
	va_list arg = NULL;
	
	CHECK_VECTOR_VALIDANCE(v, return false);
	CHECK_PARAMETERS(v->data == NULL, return false);
	
	va_start(arg, msgFormat);
	
	if(msgFormat != NULL)
	{
		vprintf(msgFormat, arg);
	}
	
	va_end(arg);
	
	for(i = 0; i < v->n; i++)
	{
		v->data[i] = get_double_input(-HUGE_VAL, HUGE_VAL, "%s%lu = ", vectorName, (unsigned long)i);
	}
	
	return true;
}

/***************************************************************/
/*                     OPERATOR FUNCTIONS                      */
/***************************************************************/

/* a+b */
double operator_binary_plus(double a, double b)
{
	return a + b;
}

/* a-b */
double operator_binary_minus(double a, double b)
{
	return a - b;
}

/* a*b */
double operator_mul(double a, double b)
{
	return a * b;
}

/* a/b */
double operator_div(double a, double b)
{
	CHECK_PARAMETERS(fabs(b) < ZERO_THRESHOLD, return HUGE_VAL);
	return a / b;
}

/* +a */
double operator_unary_plus(double a) /* do nothing */
{
	return a;
}

/* -a */
double operator_unary_minus(double a)
{
	return -a;
}

/* a^b, wrapper to pow function */
double operator_exp(double a, double b)
{
	return pow(a, b);
}


/***************************************************************/
/*             NON STANDARD MATHEMATICAL FUNCTIONS             */
/***************************************************************/

/* contangent */
double cot(double arg)
{
	return 1.0/tan(arg);
}

/* cosecant */
double csc(double arg)
{
	return 1.0/sin(arg);
}

/* secant */
double sec(double arg)
{
	return 1.0/cos(arg);
}

/* arccotangent */
double acot(double arg)
{
	return atan(1/arg);
}

/* arccosecant */
double acsc(double arg)
{
	return asin(1/arg);
}

/* arcsecant */
double asec(double arg)
{
	return acos(1/arg);
}

/* mathematical log(base, argument) */
double lg(double base, double arg)
{
	return log(arg)/log(base);
}

/* cubic root */
double cbrt(double arg)
{
	return pow(arg, 1/3);
}


/***************************************************************/
/*           HELPER FUNCTIONS FOR NUMERICAL FUNCTIONS          */
/***************************************************************/

bool is_same_sign(double a, double b)
{
	if(a == 0 && b == 0)
	{
		return true;
	}
	
	if((a >= 0 && b <= 0) || (a <= 0 && b >= 0))
	{
		return false;
	}
	
	return true;
}

bool get_mat_equation(TokenList *lst, VarList *vlst)
{
	bool isValid = false;
	TokenList infixLst = {0};
	String inputString = NULL, spacelessString = NULL;
	
	CHECK_TOKENLIST_VALIDANCE(lst, return false);
	CHECK_VARLIST_VALIDANCE(vlst, return false);
	
	inputString = get_mat_function();
	spacelessString = string_space_remove(inputString);
	
	#if (VERBOSE_LEVEL >= 2)
	printf("Original string: %s\n", inputString);
	printf("Spaceless string: %s\n", spacelessString);
	#endif
	
	tokenize_string_to_tokentype(&infixLst, spacelessString);
	
	isValid = syntax_check_msg_basic(&infixLst);	
	
	if(isValid)
	{		
		tokenize_process_equation(&infixLst);
		tokenize_type_to_data(&infixLst, vlst);
		
		isValid = syntax_check_msg_advanced(&infixLst);
		
		if(isValid)
		{
			infix_to_postfix(lst, &infixLst);
			
			#if (VERBOSE_LEVEL >= 2)
			{
				size_t i = 0;
				for(i = 0; i < infixLst.length; i++)
				{
					Token *t = &infixLst.tokens[i];
					
					printf("Token type: %s\n", TOKEN_STRINGS[t->type]);
					printf("Token string: %s\n", t->s);
					
					if(infixLst.tokens[i].type == TOKEN_VARIABLE)
					{
						printf("Variable \'%s\'=%lf\n\n", vlst->var[t->data.varIndex].name, vlst->var[t->data.varIndex].value);
					}
					else
					{
						printf("\n");
					}
				}
				
				printf(	"\n\n\n\n\n\nAFTER SHUNTING YARD ALGORITHM:\n"
						"==============================\n");
				
				for(i = 0; i < lst->length; i++)
				{
					printf("Token type: %s\n", TOKEN_STRINGS[lst->tokens[i].type]);
					printf("Token string: %s\n", lst->tokens[i].s);
					if(lst->tokens[i].type == TOKEN_VARIABLE)
					{
						printf("Variable \'%s\'=%lf\n\n", vlst->var[lst->tokens[i].data.varIndex].name, vlst->var[lst->tokens[i].data.varIndex].value);
					}
					else
					{
						printf("\n");
					}
				}
			}
			#endif			
		}
	}
	
	free(inputString);
	free(spacelessString);
	
	return isValid;
}

double next_root_bisection(double lower, double lowerVal, double upper, double upperVal)
{
	UNUSED_PARAMETER(lowerVal);
	UNUSED_PARAMETER(upperVal);
	return (upper - lower) / 2.0 + lower;
}

double next_root_regula_falsi(double lower, double lowerVal, double upper, double upperVal)
{
	return (lower * upperVal - upper * lowerVal) / (upperVal - lowerVal); /* (a*f(b)-b*f(a)) / (f(b)-f(a)) */
}

bool derivative_forward(TokenList *lst, VarList *vlst, Variable *var, double epsilon, double *result)
{
	double originalValue = 0.0;
	double resultCurrent = 0.0, resultForward = 0.0;
	
	CHECK_TOKENLIST_VALIDANCE(lst, return false);
	CHECK_VARLIST_VALIDANCE(vlst, return false);
	CHECK_VARIABLE_VALIDANCE(var, return false);
	CHECK_PARAMETERS(var->isConstant == true || epsilon == 0.0 || result == NULL, return false);
	
	originalValue = var->value;
	
	solver_solve(lst, vlst, &resultCurrent);
	
	var->value += epsilon;
	solver_solve(lst, vlst, &resultForward);
	
	var->value = originalValue;
	*result = (resultForward - resultCurrent) / epsilon;
	
	return true;
}

bool derivative_central(TokenList *lst, VarList *vlst, Variable *var, double epsilon, double *result)
{
	double originalValue = 0.0;
	double resultForward = 0.0, resultBackward;
	
	CHECK_TOKENLIST_VALIDANCE(lst, return false);
	CHECK_VARLIST_VALIDANCE(vlst, return false);
	CHECK_VARIABLE_VALIDANCE(var, return false);
	CHECK_PARAMETERS(var->isConstant == true || epsilon == 0.0 || result == NULL, return false);
	
	originalValue = var->value;
	
	var->value += epsilon;
	solver_solve(lst, vlst, &resultForward);
	
	var->value -= 2*epsilon;
	solver_solve(lst, vlst, &resultBackward);
	
	var->value = originalValue;
	*result = (resultForward - resultBackward) / (2*epsilon);
	
	return true;
}

bool derivative_backward(TokenList *lst, VarList *vlst, Variable *var, double epsilon, double *result)
{
	double originalValue = 0.0;
	double resultCurrent = 0.0, resultBackward = 0.0;
	
	CHECK_TOKENLIST_VALIDANCE(lst, return false);
	CHECK_VARLIST_VALIDANCE(vlst, return false);
	CHECK_VARIABLE_VALIDANCE(var, return false);
	CHECK_PARAMETERS(var->isConstant == true || epsilon == 0.0 || result == NULL, return false);
	
	originalValue = var->value;
	
	solver_solve(lst, vlst, &resultCurrent);
	
	var->value -= epsilon;
	solver_solve(lst, vlst, &resultBackward);
	
	var->value = originalValue;
	*result = (resultCurrent - resultBackward) / epsilon;
	
	return true;
}

bool calculate_simson_1_3(TokenList *lst, VarList *vlst, Variable *var, double upper, double lower, int n, double *result)
{	
	/* https://en.wikipedia.org/wiki/Simpson%27s_rule */
	const double h = (upper - lower) / (double)n;
	double total = 0.0, temp = 0.0;
	int i = 0;
	
	CHECK_TOKENLIST_VALIDANCE(lst, return false);
	CHECK_VARLIST_VALIDANCE(vlst, return false);
	CHECK_VARIABLE_VALIDANCE(var, return false);
	CHECK_PARAMETERS(n % 2 != 0 || n < 2, return false);
	CHECK_PARAMETERS(upper <= lower, return false);
	
	var->value = lower;
	solver_solve(lst, vlst, &temp);
	total += temp;
	
	var->value = upper;
	solver_solve(lst, vlst, &temp);
	total += temp;
	
	for(var->value = lower - h, i = 0; i < n/2; i++)
	{
		var->value += 2 * h;
		solver_solve(lst, vlst, &temp);
		total += 4 * temp;
	}
	
	for(var->value = lower, i = 0; i < n/2-1; i++)
	{
		var->value += 2 * h;
		solver_solve(lst, vlst, &temp);
		total += 2 * temp;
	}
	
	*result = h / 3.0 * total;
	
	return true;
}

bool calculate_simson_3_8(TokenList *lst, VarList *vlst, Variable *var, double upper, double lower, int n, double *result)
{	
	/* https://en.wikipedia.org/wiki/Simpson%27s_rule */
	
	const double h = (upper - lower) / (double)n;
	double total = 0.0, temp = 0.0;
	int i = 0;
	
	CHECK_TOKENLIST_VALIDANCE(lst, return false);
	CHECK_VARLIST_VALIDANCE(vlst, return false);
	CHECK_VARIABLE_VALIDANCE(var, return false);
	CHECK_PARAMETERS(n % 3 != 0 || n < 3, return false);
	CHECK_PARAMETERS(upper <= lower, return false);
	
	var->value = lower;
	solver_solve(lst, vlst, &temp);
	total += temp;
	
	var->value = upper;
	solver_solve(lst, vlst, &temp);
	total += temp;
	
	for(var->value = lower - 2 * h, i = 0; i < n-1; i+=3)
	{
		var->value += 3 * h;
		solver_solve(lst, vlst, &temp);
		total += 3 * temp;
	}
	
	for(var->value = lower - h, i = 1; i < n-1; i+=3)
	{
		var->value += 3 * h;
		solver_solve(lst, vlst, &temp);
		total += 3 * temp;
	}
	
	for(var->value = lower, i = 0; i < n/3-1; i++)
	{
		var->value += 3 * h;
		solver_solve(lst, vlst, &temp);
		total += 2 * temp;
	}
	
	*result = 3.0 * h / 8.0 * total;
	
	return true;
}


/***************************************************************/
/*                     NUMERICAL FUNCTIONS                     */
/***************************************************************/

bool method_closed(double *result, String methodName, double (*nextRoot)(double lower, double lowerVal, double upper, double upperVal))
{
	TokenList lst = {0};
	VarList vlst = {0};
	Variable *var = NULL;
	double lower = 0.0, upper = 0.0, mid = 0.0, oldMid = 0.0, tolerance = 0.0001;
	double lowerVal = 0.0, upperVal = 0.0, midVal = 0.0;
	int iteration = 0;
	
	CHECK_PARAMETERS(result == NULL, return false);
	
	if(get_mat_equation(&lst, &vlst) == false)
	{
		token_list_deinit(&lst);
		var_list_deinit(&vlst);
		return false;
	}
	
	if(var_list_non_const_count(&vlst) != 1)
	{
		token_list_deinit(&lst);
		var_list_deinit(&vlst);
		fprintf(stderr, "There must be strictly one variable for %s method\n", methodName);
		return false;
	}
	
	var = var_list_get_first_non_const(&vlst);
	
	lower = get_double_input(-HUGE_VAL, HUGE_VAL, "Enter lower boundary: ");
	upper = get_double_input(lower, HUGE_VAL, "Enter upper boundary: ");
	tolerance = get_double_input(-HUGE_VAL, HUGE_VAL, "Enter tolerance (epsilon): ");
	
	#if (VERBOSE_LEVEL >= 2)
	printf("\nLower boundary: %lf\nUpper boundary: %lf\n\n", lower, upper);
	#endif
	
	var->value = lower;
	solver_solve(&lst, &vlst, &lowerVal);
	
	var->value = upper;
	solver_solve(&lst, &vlst, &upperVal);
	
	if(is_same_sign(lowerVal, upperVal))
	{
		token_list_deinit(&lst);
		var_list_deinit(&vlst);
		fprintf(stderr, "Value of the functions signs are same at boundary values\n");
		return false;
	}
	
	#if (VERBOSE_LEVEL >= 1)
	printf("\n\n|  i  |  lower  | f(lower) |  upper  | f(upper) |   mid   |  f(mid)  |update|\n"
	           "|-----|---------|----------|---------|----------|---------|----------|------|\n");
	#endif
	
	do
	{
		oldMid = mid;
		mid = nextRoot(lower, lowerVal, upper, upperVal);
		
		var->value = mid;
		solver_solve(&lst, &vlst, &midVal);
		
		#if (VERBOSE_LEVEL >= 1)
		printf("|%5d|%9.5lf|%10.5lf|%9.5lf|%10.5lf|%9.5lf|%10.5lf|", iteration, lower, lowerVal, upper, upperVal, mid, midVal);
		#endif
		
		iteration++;
		
		if(fabs(mid - oldMid) > tolerance || iteration == 1)
		{
			if(is_same_sign(midVal, upperVal))
			{
				upper = mid;
				upperVal = midVal;
				
				#if (VERBOSE_LEVEL >= 1)
				printf(" u = m|\n");
				#endif
				
			}
			else if(is_same_sign(midVal, lowerVal))
			{
				lower = mid;
				lowerVal = midVal;
				
				#if (VERBOSE_LEVEL >= 1)
				printf(" l = m|\n");
				#endif
				
			}
		}
	}while(fabs(mid - oldMid) > tolerance || iteration == 1);
	
	#if (VERBOSE_LEVEL >= 1)
	printf("\n");
	#endif
	
	*result = var->value;
	
	token_list_deinit(&lst);
	var_list_deinit(&vlst);
	
	return true;
}

bool method_newton_raphson(double *result)
{
	TokenList lst = {0};
	VarList vlst = {0};
	Variable *var = NULL;
	double oldVar = 0.0;
	double resultCentral = 0.0, resultVal = 0.0;
	double epsilon = 0.0001;
	int iteration = 0;
	
	CHECK_PARAMETERS(result == NULL, return false);
	
	if(get_mat_equation(&lst, &vlst) == false)
	{
		token_list_deinit(&lst);
		var_list_deinit(&vlst);
		return false;
	}
	
	if(var_list_non_const_count(&vlst) != 1)
	{
		token_list_deinit(&lst);
		var_list_deinit(&vlst);
		fprintf(stderr, "There must be strictly one variable for newton-raphson\n");
		return false;
	}
	
	var = var_list_get_first_non_const(&vlst);
	
	var->value = get_double_input(-HUGE_VAL, HUGE_VAL, "Enter %s = ", var->name);
	epsilon = get_double_input(-HUGE_VAL, HUGE_VAL, "Enter tolerance (epsilon): ");
	
	
	#if (VERBOSE_LEVEL >= 1)
	printf("\n\n|  i  |      xi     |     f(xi)    |    f'(xi)    |   epsilon  |\n"
	           "|-----|-------------|--------------|--------------|------------|\n");
	#endif
	
	do
	{
		derivative_central(&lst, &vlst, var, DEFAULT_EPSILON, &resultCentral);
		
		if(resultCentral == 0.0)
		{
			token_list_deinit(&lst);
			var_list_deinit(&vlst);
			fprintf(stderr, "Central derivation is 0\n");
			return false;
		}
		
		solver_solve(&lst, &vlst, &resultVal);
		
		#if (VERBOSE_LEVEL >= 1)
		printf("|%5d|%13.7lf|%14.7lf|%14.7lf|%12.10lf|\n", iteration, var->value, resultVal, resultCentral, epsilon);
		#endif
		
		oldVar = var->value;
		var->value = var->value - (resultVal / resultCentral);
		
		iteration++;
	}while(fabs(var->value - oldVar) > epsilon);
	
	*result = var->value;
	
	token_list_deinit(&lst);
	var_list_deinit(&vlst);
	
	return true;
}

bool method_matrix_inverse(Matrix *result)
{
	Matrix inMat = {0}, outMat = {0};
	size_t N = 0, i = 0, j = 0;
	
	CHECK_PARAMETERS(result == NULL, return false);
	
	get_matrix_size_input(&N, &N, true);
	
	if(	matrix_create(&inMat, N, N) == false ||
		matrix_identity_create(&outMat, N) == false)
	{
		fprintf(stderr, "Matrix did not created\n");
		return false;
	}
	
	get_matrix_input(&inMat, "Enter matrix: \n");
	
	for(j = 0; j < N; j++)
	{
		double pivot = 0.0;
		int row = matrix_find_pivot_row(&inMat, j, j);
		
		if(row == NOT_EXIST)
		{
			fprintf(stderr, "Singular matrix\n");
			matrix_delete(&inMat);
			matrix_delete(&outMat);
			return false;
		}
		
		if((size_t)row != j) /* swap rows */
		{
			matrix_swap_rows(&inMat, row, j);
			matrix_swap_rows(&outMat, row, j);
			
			#if (VERBOSE_LEVEL >= 1)
			printf("row %d and %d swapped\n", row, j);
			matrix_print_augmented(&inMat, &outMat);
			#endif
		}
		
		pivot = inMat.data[j][j];
		
		matrix_mul_row(&inMat, j, 1.0 / pivot);
		matrix_mul_row(&outMat, j, 1.0 / pivot);
		
		#if (VERBOSE_LEVEL >= 1)
		printf("row %d multiplied by %lf\n", j, 1.0/pivot);
		matrix_print_augmented(&inMat, &outMat);
		#endif
		
		pivot = inMat.data[j][j];
		
		for(i = 0; i < N; i++)
		{
			if(i != j) /* same row */
			{
				if(fabs(inMat.data[i][j]) > ZERO_THRESHOLD) /* if not zero */
				{
					double multiplier = pivot / inMat.data[i][j];
					
					matrix_mul_row(&inMat, i, multiplier);
					matrix_mul_row(&outMat, i, multiplier);
					
					#if (VERBOSE_LEVEL >= 1)
					printf("row %d multiplied by %lf\n", i, multiplier);
					matrix_print_augmented(&inMat, &outMat);
					#endif
					
					matrix_subtract_row(&inMat, i, i, j);
					matrix_subtract_row(&outMat, i, i, j);
					
					#if (VERBOSE_LEVEL >= 1)
					printf("row%d = row%d - row%d\n", i, i, j);
					matrix_print_augmented(&inMat, &outMat);
					#endif
					
					matrix_mul_row(&inMat, i, 1.0 / multiplier);
					matrix_mul_row(&outMat, i, 1.0 / multiplier);
					
					#if (VERBOSE_LEVEL >= 1)
					printf("Normalized row %d\n", i);
					matrix_print_augmented(&inMat, &outMat);
					#endif
					
				}
			}
		}
		
	}
	
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < N; j++)
		{
			if(fabs(outMat.data[i][j]) < ZERO_THRESHOLD)
			{
				outMat.data[i][j] = 0.0;
			}
		}
	}
	
	*result = outMat;
	
	matrix_delete(&inMat);
	
	return true;
}

bool method_cholesky(Matrix *result)
{
	Matrix lower = {0}, mat = {0};
	size_t N = 0, i = 0, j = 0, k = 0;
	double total = 0.0;
	
	CHECK_PARAMETERS(result == NULL, return false);
	
	get_matrix_size_input(&N, &N, true);
	
	if(	matrix_create(&mat, N, N) == false ||
		matrix_create(&lower, N, N) == false)
	{
		fprintf(stderr, "Matrix did not created\n");
		return false;
	}
	
	get_matrix_input(&mat, "Enter matrix: \n");
	
	/* Algorithm: https://en.wikipedia.org/wiki/Cholesky_decomposition */
	
	for(j = 0; j < N; j++)
	{		
		for(total = 0.0, k = 0; k < j; k++)
		{
			total += pow(lower.data[j][k], 2);
		}
		
		if(mat.data[j][j] - total < 0.0)
		{
			fprintf(stderr, "Matrix is not positive defined or symmetric\n");
			matrix_delete(&mat);
			matrix_delete(&lower);
			return false;
		}
		
		lower.data[j][j] = sqrt(mat.data[j][j] - total);
		
		for(i = j+1; i < N; i++)
		{
			for(total = 0.0, k = 0; k < j; k++)
			{
				total +=lower.data[i][k] * lower.data[j][k];
			}
			
			lower.data[i][j] = (mat.data[i][j] - total) / lower.data[j][j];
		}
	}
	*result = lower;
	
	matrix_delete(&mat);
	
	return true;
}

bool method_gauss_seidal(Vector *result)
{
	Matrix mat = {0};
	Vector variables = {0};
	Vector constants = {0};
	double tolerance = 0.0;
	double maxDiff = 0.0;
	int iteration = 0, divergenceCount = 0;
	size_t i = 0, N = 0;
	
	CHECK_PARAMETERS(result == NULL, return false);
	
	get_matrix_size_input(&N, &N, true);
	
	matrix_create(&mat, N, N);
	get_matrix_input(&mat, "Enter coefficient matrix (matrix A in Ax=b): \n");
	
	vector_create(&constants, N);
	get_vector_input(&constants, "b", "Enter constant values (vector b in Ax=b): \n");
	
	vector_create(&variables, N);
	get_vector_input(&variables, "x", "Enter initial values (vector x in Ax=b): \n");
	
	tolerance = get_double_input(-HUGE_VAL, HUGE_VAL, "Enter tolerance (epsilon): ");
	
	#if (VERBOSE_LEVEL >= 1)
	
	printf("\n\n|  i  |");
	for(i = 0; i < N; i++)
	{
		printf("    x%02d    |", i+1);
	}
	printf("  Max Diff  |\n");
	printf("|-----|");
	for(i = 0; i < N; i++)
	{
		printf("-----------|");
	}
	printf("------------|\n");
	#endif
	
	do
	{
		double oldMaxDiff = maxDiff;
		maxDiff = 0.0;
		
		for(i = 0; i < mat.row; i++)
		{
			size_t j = 0;
			double newValue = constants.data[i];
			
			for(j = 0; j < mat.col; j++)
			{
				if(j != i)
				{
					newValue -= mat.data[i][j] * variables.data[j];
				}
			}
			newValue /= mat.data[i][i];
			
			maxDiff = MAX(maxDiff, fabs(variables.data[i] - newValue));
			
			variables.data[i] = newValue;
		}
		
		iteration++;
		
		#if (VERBOSE_LEVEL >= 1)
		printf("|%5d|", iteration);
		for(i = 0; i < N; i++)
		{
			printf("%11.6lf|", variables.data[i]);
		}
		printf("%12.7lf|\n", maxDiff);
		#endif
		
		if(maxDiff > oldMaxDiff)
		{
			divergenceCount++;
		}
		else
		{
			divergenceCount = 0;
		}
		
		if(divergenceCount >= DIVERGENCE_THRESHOLD)
		{
			matrix_delete(&mat);
			vector_delete(&variables);
			vector_delete(&constants);
			fprintf(stderr, "Equation diverged\n");
			return false;
		}
		
	}while(maxDiff >= tolerance);
	
	*result = variables;
	
	matrix_delete(&mat);
	vector_delete(&constants);
	
	return true;
}

bool method_numerical_derivative(double *forward, double *central, double *backward)
{
	TokenList lst = {0};
	VarList vlst = {0};
	Variable *var = NULL;
	double resultForward = 0.0, resultCentral = 0.0, resultBackward = 0.0;
	double epsilon = 0.0001;
	
	CHECK_PARAMETERS(forward == NULL, return false);
	CHECK_PARAMETERS(central == NULL, return false);
	CHECK_PARAMETERS(backward == NULL, return false);
	
	if(get_mat_equation(&lst, &vlst) == false)
	{
		token_list_deinit(&lst);
		var_list_deinit(&vlst);
		return false;
	}
	
	if(var_list_non_const_count(&vlst) != 1)
	{
		token_list_deinit(&lst);
		var_list_deinit(&vlst);
		fprintf(stderr, "There must be strictly one variable for numerical derivative\n");
		return false;
	}
	
	var = var_list_get_first_non_const(&vlst);
	
	var->value = get_double_input(-HUGE_VAL, HUGE_VAL, "Enter %s = ", var->name);
	epsilon = get_double_input(-HUGE_VAL, HUGE_VAL, "Enter epsilon: ");
	
	if(derivative_forward(&lst, &vlst, var, epsilon, &resultForward) &&
	   derivative_central(&lst, &vlst, var, epsilon, &resultCentral) &&
	   derivative_backward(&lst, &vlst, var, epsilon, &resultBackward))
	{
		*forward = resultForward;
		*central = resultCentral;
		*backward = resultBackward;
		
		token_list_deinit(&lst);
		var_list_deinit(&vlst);
		
		return true;
	}
	
	token_list_deinit(&lst);
	var_list_deinit(&vlst);
	
	fprintf(stderr, "Error while getting derivative\n");
	return false;
}

bool method_simson(double *result1Div3, double *result3Div8)
{
	TokenList lst = {0};
	VarList vlst = {0};
	Variable *var = NULL;
	int subRange1Div3 = 0, subRange3Div8 = 0;
	double lower = 0.0, upper = 0.0;
	double temp1Div3 = 0.0, temp3Div8 = 0.0;
	
	CHECK_PARAMETERS(result1Div3 == NULL || result3Div8 == NULL, return false);
	
	if(get_mat_equation(&lst, &vlst) == false)
	{
		token_list_deinit(&lst);
		var_list_deinit(&vlst);
		return false;
	}
	
	if(var_list_non_const_count(&vlst) != 1)
	{
		token_list_deinit(&lst);
		var_list_deinit(&vlst);
		fprintf(stderr, "There must be strictly one variable for numerical integration method\n");
		return false;
	}
	
	var = var_list_get_first_non_const(&vlst);
	
	lower = get_double_input(-HUGE_VAL, HUGE_VAL, "Enter lower limit: ");
	upper = get_double_input(lower, HUGE_VAL, "Enter upper limit: ");
	
	do
	{
		subRange1Div3 = get_integer_input(2, INT_MAX, "Enter sub range count for simson 1/3 (must be even): ");
		if(subRange1Div3 % 2 != 0)
		{
			fprintf(stderr, "value must be even\n");
		}
	}while(subRange1Div3 % 2 != 0);
	
	do
	{
		subRange3Div8 = get_integer_input(3, INT_MAX, "Enter sub range count for simson 3/8 (must be multiple of 3): ");
		if(subRange3Div8 % 3 != 0)
		{
			fprintf(stderr, "value must be multiple of 3\n");
		}
	}while(subRange3Div8 % 3 != 0);
	
	if(calculate_simson_1_3(&lst, &vlst, var, upper, lower, subRange1Div3, &temp1Div3) == false)
	{
		token_list_deinit(&lst);
		var_list_deinit(&vlst);
		return false;
	}
	
	if(calculate_simson_3_8(&lst, &vlst, var, upper, lower, subRange3Div8, &temp3Div8) == false)
	{
		token_list_deinit(&lst);
		var_list_deinit(&vlst);
		return false;
	}
	
	*result1Div3 = temp1Div3;
	*result3Div8 = temp3Div8;
	
	token_list_deinit(&lst);
	var_list_deinit(&vlst);
	
	return true;
}

bool method_trapezoid(double *result)
{
	TokenList lst = {0};
	VarList vlst = {0};
	Variable *var = NULL;
	int subRange = 0.0, i = 0;
	double h = 0.0, total = 0.0, temp = 0.0;
	double lower = 0.0, upper = 0.0;
	
	CHECK_PARAMETERS(result == NULL, return false);
	
	if(get_mat_equation(&lst, &vlst) == false)
	{
		token_list_deinit(&lst);
		var_list_deinit(&vlst);
		return false;
	}
	
	if(var_list_non_const_count(&vlst) != 1)
	{
		token_list_deinit(&lst);
		var_list_deinit(&vlst);
		fprintf(stderr, "There must be strictly one variable for trapezoid method\n");
		return false;
	}
	
	var = var_list_get_first_non_const(&vlst);
	
	lower = get_double_input(-HUGE_VAL, HUGE_VAL, "Enter lower limit: ");
	upper = get_double_input(lower, HUGE_VAL, "Enter upper limit: ");
	
	subRange = get_integer_input(1, INT_MAX, "Enter sub range count for trapezoid: ");
	
	h = (upper - lower) / subRange;
	
	var->value = lower;
	solver_solve(&lst, &vlst, &temp);
	total += temp;
	
	var->value = upper;
	solver_solve(&lst, &vlst, &temp);
	total += temp;
	
	for(var->value = lower + h, i = 0; i < subRange-1; var->value += h, i++)
	{
		solver_solve(&lst, &vlst, &temp);
		total += 2 * temp;
	}
	
	*result = h / 2.0 * total;
	
	token_list_deinit(&lst);
	var_list_deinit(&vlst);
	
	return true;
}

bool method_gregory_interpolation(double *result)
{
	size_t N = 0, i = 0, j = 0;
	double firstX = 0.0, differenceX = 0.0, find = 0.0, total = 0.0, last = 1.0;
	Matrix mat = {0};
	
	CHECK_PARAMETERS(result == NULL, return false);
	
	N = get_size_input(0, INT_MAX, "Enter point count: ");
	
	if(matrix_create(&mat, N, N) == false)
	{
		fprintf(stderr, "Matrix did not created\n");
		return false;
	}
	
	firstX = get_double_input(-HUGE_VAL, HUGE_VAL, "Enter first X position: ");
	differenceX = get_double_input(-HUGE_VAL, HUGE_VAL, "Enter forward differences of X: ");
	
	for(i = 0; i < N; i++)
	{
		mat.data[i][0] = get_double_input(-HUGE_VAL, HUGE_VAL, "y%d = ", i+1);
	}
	
	for(j = 1; j < N; j++)
	{
		for(i = 0; i < N-j; i++)
		{
			mat.data[i][j] =  mat.data[i+1][j-1] - mat.data[i][j-1];
		}
	}
	
	find = get_double_input(-HUGE_VAL, HUGE_VAL, "Enter value X you want to find y: ");
	
	#if (VERBOSE_LEVEL >= 1)
	printf("\nForward differences matrix:\n");
	matrix_print(&mat);
	#endif
	
	total = mat.data[0][0];
	
	#if (VERBOSE_LEVEL >= 1)
	printf("i: %d   result: %lf\n", i, total);
	#endif
	
	for(i = 1; i < N; i++)
	{
		last = last * (find - (firstX + differenceX * (i-1))) / (differenceX * i);
		total += mat.data[0][i] * last;
			
		#if (VERBOSE_LEVEL >= 1)
		printf("i: %d   result: %lf\n", i, total);
		#endif
	}
	
	matrix_delete(&mat);
	
	*result = total;
	
	return true;
}
