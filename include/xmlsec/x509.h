/** 
 * XMLSec library
 *
 * X509 support
 *
 * See Copyright for the status of this software.
 * 
 * Author: Aleksey Sanin <aleksey@aleksey.com>
 */
#ifndef __XMLSEC_X509_H__
#define __XMLSEC_X509_H__    

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */ 

#ifndef XMLSEC_NO_X509

/* forward declarations */
typedef struct _xmlSecX509Data xmlSecX509Data, *xmlSecX509DataPtr;
typedef struct _xmlSecX509Store xmlSecX509Store, *xmlSecX509StorePtr;

typedef enum {
    xmlSecX509DataTypeUnknown = 0,
    xmlSecX509DataTypeVerifiedCert,
    xmlSecX509DataTypeTrustedCert,
    xmlSecX509DataTypeCert,
    xmlSecX509DataTypeCrl
} xmlSecX509DataType;

#include <libxml/tree.h>
#include <xmlsec/xmlsec.h>
#include <xmlsec/transforms.h>

XMLSEC_EXPORT xmlSecX509DataPtr	xmlSecX509DataCreate		(void);
XMLSEC_EXPORT void		xmlSecX509DataDestroy		(xmlSecX509DataPtr x509Data);
XMLSEC_EXPORT size_t		xmlSecX509DataGetCertsNumber	(xmlSecX509DataPtr x509Data);
XMLSEC_EXPORT size_t		xmlSecX509DataGetCrlsNumber	(xmlSecX509DataPtr x509Data);
XMLSEC_EXPORT int		xmlSecX509DataReadDerCert	(xmlSecX509DataPtr x509Data,
							 	 xmlChar *buf,
								 size_t size,
								 int base64);
XMLSEC_EXPORT void		xmlSecX509DataSetVerificationTime(xmlSecX509DataPtr x509Data,
								 time_t t);
XMLSEC_EXPORT xmlChar*		xmlSecX509DataWriteDerCert	(xmlSecX509DataPtr x509Data,
								 int pos);
XMLSEC_EXPORT int		xmlSecX509DataReadDerCrl	(xmlSecX509DataPtr x509Data,
								 xmlChar *buf,
								 size_t size,
								 int base64);
XMLSEC_EXPORT xmlChar*		xmlSecX509DataWriteDerCrl	(xmlSecX509DataPtr x509Data,
								 int pos);
XMLSEC_EXPORT int		xmlSecX509DataReadPemCert	(xmlSecX509DataPtr x509Data,
							 	const char *filename);
XMLSEC_EXPORT xmlSecX509DataPtr	xmlSecX509DataDup		(xmlSecX509DataPtr x509Data);
XMLSEC_EXPORT xmlSecKeyPtr	xmlSecX509DataCreateKey		(xmlSecX509DataPtr x509Data);
XMLSEC_EXPORT void		xmlSecX509DataDebugDump		(xmlSecX509DataPtr x509Data,
							 	FILE *output);
XMLSEC_EXPORT void		xmlSecX509DataDebugXmlDump	(xmlSecX509DataPtr x509Data,
							 	FILE *output);


XMLSEC_EXPORT xmlSecX509StorePtr xmlSecX509StoreCreate		(void);
XMLSEC_EXPORT void		xmlSecX509StoreDestroy		(xmlSecX509StorePtr store);
XMLSEC_EXPORT xmlSecX509DataPtr	xmlSecX509StoreFind		(xmlSecX509StorePtr store,
								 xmlChar *subjectName, 
								 xmlChar *issuerName, 
								 xmlChar *issuerSerial,
								 xmlChar *ski,
								 xmlSecX509DataPtr x509Data);
XMLSEC_EXPORT int		xmlSecX509StoreVerify		(xmlSecX509StorePtr store,
								 xmlSecX509DataPtr x509Data);
XMLSEC_EXPORT int		xmlSecX509StoreLoadPemCert	(xmlSecX509StorePtr store,
								 const char *filename,
								 int trusted);
XMLSEC_EXPORT int		xmlSecX509StoreAddCertsDir	(xmlSecX509StorePtr store, 
							 	 const char *path);
XMLSEC_EXPORT xmlSecKeyPtr	xmlSecPKCS12ReadKey		(const char *filename, 
								 const char *pwd);


#else /*  XMLSEC_NO_X509 */
typedef void* 	xmlSecX509Data, *xmlSecX509DataPtr;
typedef void* 	xmlSecX509Store, *xmlSecX509StorePtr;

#endif /* XMLSEC_NO_X509 */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __XMLSEC_X509_H__ */

