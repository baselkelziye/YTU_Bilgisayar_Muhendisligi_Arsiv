import AccessControl from 'accesscontrol';
const ac = new AccessControl();

exports.roles = (function () {
  ac.grant('user').readAny('travel');
  ac.grant('user').readAny('fee');
  ac.grant('user').readAny('plan');
  ac.grant('admin').extend('user').readAny('user');
  ac.grant('admin').extend('user').deleteAny('user');
  ac.grant('admin').extend('user').deleteAny('travel');
  ac.grant('accountant').extend('user').updateAny('travel');
  ac.grant('accountant').extend('user').updateAny('fee');
  ac.grant('accountant').extend('user').createAny('fee');
  ac.grant('accountant').extend('user').deleteAny('fee');
  ac.grant('accountant').extend('user').updateAny('fee');
  ac.grant('accountant').extend('user').updateAny('plan');
  ac.grant('accountant').extend('user').createAny('plan');
  ac.grant('accountant').extend('user').deleteAny('plan');
  ac.grant('employee').extend('user').createAny('travel');
  ac.grant('employee').extend('user').deleteAny('plan');

  return ac;
})();
