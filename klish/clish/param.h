/*
 * param.h
 */
/**
\ingroup clish
\defgroup clish_param param
@{

\brief This class represents an instance of a parameter type.

Parameter instances are assocated with a command line and used to validate the
the arguments which a user is inputing for a command.

*/
#ifndef _clish_param_h
#define _clish_param_h

typedef struct clish_paramv_s clish_paramv_t;
typedef struct clish_param_s clish_param_t;

#include "clish/ptype.h"

/**
 * The means by which the param is interpreted.
 */
typedef enum {
    /**
     * A common parameter.
    */
	CLISH_PARAM_COMMON,
    /**
     * A swich parameter.
     * Choose the only one of nested parameters.
     */
	CLISH_PARAM_SWITCH,
    /**
     * A subcomand.
     * Identified by it's name.
     */
	CLISH_PARAM_SUBCOMMAND
} clish_param_mode_e;

/*=====================================
 * PARAM INTERFACE
 *===================================== */
/*-----------------
 * meta functions
 *----------------- */
clish_param_t *clish_param_new(const char *name,
			       const char *text, clish_ptype_t * ptype);
/*-----------------
 * methods
 *----------------- */
void clish_param_delete(clish_param_t * instance);
void clish_param_help(const clish_param_t * instance, size_t offset);
void clish_param_help_arrow(const clish_param_t * instance, size_t offset);
char *clish_param_validate(const clish_param_t * instance, const char *text);
void clish_param_dump(const clish_param_t * instance);
void clish_param_insert_param(clish_param_t * instance, clish_param_t * param);
/*-----------------
 * attributes
 *----------------- */
const char *clish_param__get_name(const clish_param_t * instance);
const char *clish_param__get_text(const clish_param_t * instance);
const char *clish_param__get_range(const clish_param_t * instance);
const char *clish_param__get_default(const clish_param_t * instance);
clish_ptype_t *clish_param__get_ptype(const clish_param_t * instance);
void clish_param__set_default(clish_param_t * instance, const char *defval);
void clish_param__set_mode(clish_param_t * instance, clish_param_mode_e mode);
clish_param_mode_e clish_param__get_mode(const clish_param_t * instance);

clish_param_t *clish_param__get_param(const clish_param_t * instance,
				unsigned index);
const unsigned clish_param__get_param_count(const clish_param_t * instance);
clish_paramv_t *clish_param__get_paramv(clish_param_t * instance);
void clish_param__set_optional(clish_param_t * instance, bool_t optional);
bool_t clish_param__get_optional(const clish_param_t * instance);

/* paramv methods */
clish_paramv_t *clish_paramv_new(void);
void clish_paramv_delete(clish_paramv_t * instance);
void clish_paramv_insert(clish_paramv_t * instance, clish_param_t * param);
clish_param_t *clish_paramv__get_param(const clish_paramv_t * instance,
				unsigned index);
const unsigned clish_paramv__get_count(const clish_paramv_t * instance);


#endif				/* _clish_param_h */
/** @} clish_param */
