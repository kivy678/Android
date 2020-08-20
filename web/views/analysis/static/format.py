# -*- coding:utf-8 -*-

##########################################################################

from flask.views import MethodView
from flask import render_template, request

from web.views.analysis import view_static

from util.fsUtils import Join, Walk

from common import getSharedPreferences
from webConfig import SHARED_PATH

from web.session import getSession

import elfformat

##########################################################################

sp 					= getSharedPreferences(SHARED_PATH)
DECODE_DIR			= sp.getString('DECODE_DIR')

##########################################################################

class FileFormat(MethodView):
    template_name = None

    def __init__(self, template_name):
        self.template_name = template_name

    def get(self):
        analysis_path = Join(DECODE_DIR, getSession('fileName'), 'unzip')
        lib_path = Join(analysis_path, 'lib')
        data = map(lambda x: x.replace(lib_path, 'lib'), Walk(lib_path))

        return render_template(self.template_name, enter=data)

    def post(self):
        analysis_path = Join(DECODE_DIR, getSession('fileName'), 'unzip')
        lib_path = Join(analysis_path, request.form.get('lib'))

        return "<pre>" + '\n'.join([i for i in elfformat.parser(lib_path)]) + "<pre>"


ft = FileFormat.as_view('format', template_name='analysis/static/format.jinja')
view_static.add_url_rule('format', view_func=ft)
