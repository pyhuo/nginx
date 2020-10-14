//
// Created by huoyinghui on 2020/10/14.
//

#include <ngx_config.h>
#include <ngx_core.h>
#include <ngx_http.h>



// 1.学习基本的数据类型
// 1.字符串
// 2.list链表
// 3.hast字典: http请求头
//ngx_str_t
//ngx_list_part_t
//ngx_table_elt_t

static char *
ngx_http_mytest_block(ngx_conf_t *cf, ngx_command_t *cmd, void *conf)
{
    ngx_str_t               name;
    name = cmd->name;
    ngx_conf_log_error(NGX_LOG_EMERG, cf, 0,
                       "Test invalid variable name \"%V\"", &name);
    return NGX_CONF_OK;
}


static ngx_command_t  ngx_http_mytest_commands[] = {

        { ngx_string("mytest"),
          NGX_HTTP_MAIN_CONF|NGX_CONF_BLOCK|NGX_CONF_TAKE12,
          ngx_http_mytest_block,
          NGX_HTTP_MAIN_CONF_OFFSET,
          0,
          NULL },

        ngx_null_command
};


static ngx_http_module_t  ngx_http_mytest_module_ctx = {
        NULL,                                  /* preconfiguration */
        NULL,                                  /* postconfiguration */

        NULL,                                  /* create main configuration */
        NULL,                                  /* init main configuration */

        NULL,                                  /* create server configuration */
        NULL,                                  /* merge server configuration */

        NULL,                                  /* create location configuration */
        NULL                                   /* merge location configuration */
};


ngx_module_t  ngx_http_mytest_module = {
        NGX_MODULE_V1,
        &ngx_http_mytest_module_ctx,              /* module context */
        ngx_http_mytest_commands,                 /* module directives */
        NGX_HTTP_MODULE,                       /* module type */
        NULL,                                  /* init master */
        NULL,                                  /* init module */
        NULL,                                  /* init process */
        NULL,                                  /* init thread */
        NULL,                                  /* exit thread */
        NULL,                                  /* exit process */
        NULL,                                  /* exit master */
        NGX_MODULE_V1_PADDING
};
