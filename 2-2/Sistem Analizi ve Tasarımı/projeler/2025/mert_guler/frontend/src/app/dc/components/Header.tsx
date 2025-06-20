import React from 'react';
import '../style/Chat.css';

interface RoleBadgeProps {
    role?: string | null;
}

const RoleBadge: React.FC<RoleBadgeProps> = ({ role }) => {
    const displayRole = role ?? 'USER';

    let modifierClass = '';
    switch (displayRole) {
        case 'ADMIN':
            modifierClass = 'role-badge--admin';
            break;
        case 'USER':
            modifierClass = 'role-badge--user';
            break;
        default:
            modifierClass = 'role-badge--default';
    }

    return (
        <div
            className={`role-badge ${modifierClass}`}
            aria-label={`User role: ${displayRole}`}
        >
            <span className="role-badge__value">{displayRole}</span>
        </div>
    );
};

interface AdminHeaderProps {
    userRole?: string | null;
}

const AdminHeader: React.FC<AdminHeaderProps> = ({ userRole }) => (
    <RoleBadge role={userRole} />
);

export default AdminHeader;
